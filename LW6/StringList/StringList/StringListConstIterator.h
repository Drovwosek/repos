#pragma once
#include <iostream>
#include <exception>
#include <memory>
#include <iterator>
#include <cassert>
#include <iostream>
#include "StringList.h"

class CStringList;
struct CStringListMember;

class CListConstIterator
{
	friend class CStringList;
public:
	using iterator_category = std::bidirectional_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = const std::string;
	using pointer = const std::string*;
	using reference = const std::string&;

	const std::string& operator*() const;

	bool operator==(const CListConstIterator& it) const;
	bool operator!=(const CListConstIterator& it) const;

	CListConstIterator& operator++();
	CListConstIterator& operator--();

	CListConstIterator operator++(int);
	CListConstIterator operator--(int);
private:
	CListConstIterator(CStringListMember* value);

	CStringListMember* m_pNode;
};

CListConstIterator::CListConstIterator(CStringListMember* value)
	:m_pNode(value)
{}

bool CListConstIterator::operator==(const CListConstIterator& it) const
{
	return m_pNode == it.m_pNode;
}

bool CListConstIterator::operator!=(const CListConstIterator& it) const
{
	return m_pNode != it.m_pNode;
}

const std::string& CListConstIterator::operator*() const
{
	return m_pNode->data.value();
}

CListConstIterator& CListConstIterator::operator--()
{
	if (m_pNode->prev != nullptr)
	{
		m_pNode = m_pNode->prev;
	}
	return *this;
}

CListConstIterator& CListConstIterator::operator++()
{
	if (m_pNode->next != nullptr)
	{
		m_pNode = m_pNode->next;
	}
	return *this;
}

CListConstIterator CListConstIterator::operator--(int)
{
	CListConstIterator tmp(*this);
	--(*this);
	return tmp;
}

CListConstIterator CListConstIterator::operator++(int)
{
	CListConstIterator tmp(*this);
	++(*this);
	return tmp;
}