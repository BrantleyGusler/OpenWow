#pragma once
/**
 * StructuredBuffer is a read/write-able buffer.
 * The buffer can contain any data that can be accessed in the shader.
 */

#include "Buffer.h"

class StructuredBuffer : public IBuffer
{
public:
	// Bind the buffer for rendering.
	virtual bool Bind(uint32 id, std::weak_ptr<Shader> shader, ShaderParameter::Type parameterType) = 0;
	// Unbind the buffer for rendering.
	virtual void UnBind(uint32 id, std::weak_ptr<Shader> shader, ShaderParameter::Type parameterType) = 0;

	// Is this an index buffer or an attribute/vertex buffer?
	virtual BufferType GetType() const = 0;
	// How many elements does this buffer contain?
	virtual uint32 GetElementCount() const = 0;

	// Copy the contents of another buffer to this one.
	// Buffers must be the same size.
	virtual void Copy(std::shared_ptr<StructuredBuffer> other) = 0;

	// Set the buffer data.
	template<typename T>
	void Set(const std::vector<T>& value);

	// Clear the contents of the buffer.
	virtual void Clear() = 0;

protected:
	virtual void SetData(void* data, size_t elementSize, size_t offset, size_t numElements) = 0;

};

// Template parameter specializations.
#include "StructuredBuffer.inl"