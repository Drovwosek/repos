#pragma once
#include <string>
#include <vector>
#include <sstream>
#include <cassert>

class CBody
{
public:
	virtual double GetDestiny() const = 0;
	virtual double GetVolume() const = 0;
	virtual double GetMass() const = 0;
	std::string ToString() const;

	std::string GetType() const;
	CBody* GetParent() const;
	void SetParrent(CBody* parent);

protected:
	CBody(std::string type);

private:
	std::string m_type;
	CBody* m_parent;

	virtual void AppendProperties(std::ostream& stream) const = 0;
};

Using bodyPtr = std::shared_ptr<CBody>;
