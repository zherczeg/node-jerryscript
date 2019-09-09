#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "v8env.h"
#include "assert.h"

int main(int argc, char* argv[]) {
    // Initialize V8.
    V8Environment env(argc, argv);

    /* Helper arrays */
    uint8_t uint8Data[] = { 1, 1, 0, 0, 0, 0, 0, 0 };
    double float64Data[] = { 3.14, 1.21 };

    /* Array */
    v8::Local<v8::Array> array = v8::Array::New(env.getIsolate(), 3);
    ASSERT_EQUAL(array->IsArray(), true);

    /* ArrayBuffer */
    v8::Local<v8::ArrayBuffer> uint8Buffer =
        v8::ArrayBuffer::New(env.getIsolate(), (void*) uint8Data, 8, v8::ArrayBufferCreationMode::kInternalized);
    v8::Local<v8::ArrayBuffer> float64Buffer =
        v8::ArrayBuffer::New(env.getIsolate(), (void*) float64Data, 16, v8::ArrayBufferCreationMode::kInternalized);

    ASSERT_EQUAL(uint8Buffer->IsArrayBuffer(), true);
    ASSERT_EQUAL(float64Buffer->IsArrayBuffer(), true);

    /* TypedArray */
    v8::Local<v8::Uint8Array> uint8Array = v8::Uint8Array::New(uint8Buffer, 0, 5);
    v8::Local<v8::Uint32Array> uint32Array = v8::Uint32Array::New(uint8Buffer, 0, 1);
    v8::Local<v8::Float64Array> float64Array = v8::Float64Array::New(float64Buffer, 0, 1);

    ASSERT_EQUAL(uint8Array->IsUint8Array(), true);
    ASSERT_EQUAL(float64Array->IsFloat64Array(), true);

    /* Numeric types */
    v8::Local<v8::Integer> integer = v8::Integer::New(env.getIsolate(), -23);
    v8::Local<v8::Integer> integer2 = v8::Integer::NewFromUnsigned(env.getIsolate(), 23);
    v8::Local<v8::Number> number = v8::Number::New(env.getIsolate(), 3.14);

    ASSERT_EQUAL(integer->IsInt32(), true);
    ASSERT_EQUAL(integer2->IsInt32(), true);
    ASSERT_EQUAL(number->IsNumber(), true);
    ASSERT_EQUAL(number->IsInt32(), false);

    /* String */
    v8::Local<v8::String> string = v8::String::NewFromUtf8(env.getIsolate(), "String", v8::NewStringType::kNormal).ToLocalChecked();
    // Fixme: IsString is defined in the v8.h file.
    // ASSERT_EQUAL(number->IsString(), true);

    /* External */
    v8::Local<v8::External> external = v8::External::New(env.getIsolate(), (void*) 2);
    ASSERT_EQUAL(external->IsExternal(), true);

    /* Object */
    v8::Local<v8::Object> object = v8::Object::New(env.getIsolate());
    ASSERT_EQUAL(object->IsObject(), true);

    /* Map */
    v8::Local<v8::Map> map = v8::Map::New(env.getIsolate());
    //ASSERT_EQUAL(map->IsMap(), true);

    /* Private */
    v8::Local<v8::Private> priv = v8::Private::New(env.getIsolate(), string);

    /* Symbol */
    v8::Local<v8::Symbol> symbol = v8::Symbol::New(env.getIsolate(), string);
    ASSERT_EQUAL(symbol->IsSymbol(), true);

    return 0;
}