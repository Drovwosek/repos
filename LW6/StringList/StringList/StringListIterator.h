/*
Определяем класс CListIterator, который является итератором для класса CStringList. 
Этот класс реализует функционал для итерации по элементам списка. 

 CStringList является другом класса CListIterator, это позволяет классу CListIterator получить доступ к закрытым членам класса CStringList. 
Типы, которые определяют свойства итератора: iterator_category, difference_type, value_type, pointer, reference. 
Эти типы помогают определить категорию итератора, разницу между итераторами, тип значения, указатель. 
Методы и операторы класса CListIterator: 
Оператор разыменования operator*(), который возвращает ссылку на данные элемента, на который указывает итератор. 
Операторы сравнения operator==() и operator!=(). 
Операторы инкремента и декремента. 
Постфиксные операторы инкремента и декремента, которые возвращают временную копию итератора до его изменения.  
Этот класс CListIterator обеспечивает возможность итерироваться по элементам списка и осуществлять различные операции.
*/
#pragma once
#include <iostream>
#include <exception>
#include <memory>
#include <iterator>
#include <cassert>
#include <iostream>
#include "StringList.h"
#include "StringListConstIterator.h"

/*добавлять инклуды это шляпа*/
class CStringList;

class CListIterator
{
	friend class CStringList;
public:
	using iterator_category = std::bidirectional_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = std::string;
	using pointer = std::string*;
	using reference = std::string&;

	std::string& operator*() const;

	bool operator==(const CListIterator& it) const;
	bool operator!=(const CListIterator& it) const;

	CListIterator& operator++();
	CListIterator& operator--();

	CListIterator operator++(int);
	CListIterator operator--(int);
private:
	CListIterator(CStringListMember* value);

	CStringListMember* m_pNode;
};

CListIterator::CListIterator(CStringListMember* value)
	:m_pNode(value)
{}

bool CListIterator::operator==(const CListIterator& it) const
{
	return m_pNode == it.m_pNode;
}

bool CListIterator::operator!=(const CListIterator& it) const
{
	return m_pNode != it.m_pNode;
}

std::string& CListIterator::operator*() const
{
	return m_pNode->data.value();
}

CListIterator& CListIterator::operator--()
{
	if (m_pNode->prev != nullptr)
	{
		m_pNode = m_pNode->prev;
	}
	return *this;
}

CListIterator& CListIterator::operator++()
{
	if (m_pNode->next != nullptr)
	{
		m_pNode = m_pNode->next;
	}
	return *this;
}

CListIterator CListIterator::operator--(int)
{
	CListIterator tmp(*this);
	--(*this);
	return tmp;
}

CListIterator CListIterator::operator++(int)
{
	CListIterator tmp(*this);
	++(*this);
	return tmp;
}