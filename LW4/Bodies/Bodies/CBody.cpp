#include "CBody.h"

using namespace std;

CBody::CBody(string type)
	:m_type(type),
	m_parent(nullptr)
{

};

CBody* CBody::GetParent() const
{
	return m_parent;
};

void CBody::SetParrent() const
{
	m_parent = parent;
};

string CBody::GetType() const
{
	return Type;
};

string CBody::ToString() const
{
	ostringstream info;
	info << "Body type is " << m_type << ". "
		<< "Massa is " << round(GetMass() * 1000) / 1000 << ". "
		<< "Volume is " << round(GetVolume() * 1000) / 1000 << ". "
		<< "Density is " << round(GetDensity() * 1000) / 1000 << ". ";
	
	AppendProperties(info);

	return info.str();
};
