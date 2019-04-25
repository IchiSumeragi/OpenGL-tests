#include "IndexBuffer.h"

#include "Renderer.h"
#include <iostream>

IndexBuffer::IndexBuffer(const unsigned int* data, const unsigned int count)
	:m_Count(std::move(count))
{
	ASSERT(sizeof(unsigned int) == sizeof(GLuint));

	GLCall(glGenBuffers(1, &m_RendererID));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}

////copy constructor
//IndexBuffer::IndexBuffer(const IndexBuffer& other)
//	: m_RendererID(other.m_RendererID), m_Count(other.m_Count)
//{
//}
//
////move constructor
//IndexBuffer::IndexBuffer(IndexBuffer &&other)
//{
//	m_RendererID = other.m_RendererID;
//	m_Count = other.m_Count;
//}
//
//IndexBuffer& IndexBuffer::operator=(IndexBuffer& other)
//{
//	if (this != &other)
//	{
//		//GLCall(glDeleteBuffers(1, &m_RendererID));
//		m_RendererID = other.m_RendererID;
//		m_Count = other.m_Count;
//		other.m_Count = 0;
//		other.m_RendererID = 0;
//	}
//
//	return *this;
//}
//
////assignment operator
//IndexBuffer & IndexBuffer::operator=(IndexBuffer && other)
//{
//	if (this != &other)
//	{
//		//GLCall(glDeleteBuffers(1, &m_RendererID));
//		m_RendererID = other.m_RendererID;
//		m_Count = other.m_Count;
//		other.m_Count = 0;
//		other.m_RendererID = 0;
//	}
//
//	return *this;
//}

IndexBuffer::~IndexBuffer()
{
	if (m_RendererID)
		GLCall(glDeleteBuffers(1, &m_RendererID));
}

void IndexBuffer::Bind() const
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
}

void IndexBuffer::Unbind() const
{
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}