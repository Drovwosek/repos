#include <catch/catch.hpp>

#include "../bodies/CSphere.h"
#include "../bodies/CParallelepiped.h"
#include "../bodies/CCylinder.h"
#include "../bodies/CCone.h"
#include "../bodies/CCompound.h"

/*�����*/
const double DENSITY_SPHERE = 30;
const double RADIUS_SPHERE = 3;
const double MASS_SPHERE = 3392.92;
const double VOLUME_SPHERE = 113.097;
const std::string STRING_SPHERE = "Body type is sphere. Massa is 3392.92. Volume is 113.097. Density is 30. Radius is 3.";

TEST_CASE("Check sphera")
{
	CSphere sphere(DENSITY_SPHERE, RADIUS_SPHERE);

	/*���������, ���� �� � ���� ���������*/
	REQUIRE(sphere.GetDensity() == DENSITY_SPHERE);

	/*���������, ���� �� � ����� ������*/
	REQUIRE(sphere.GetRadius() == RADIUS_SPHERE);

	/*���������, ���������� ������ � �����*/
	REQUIRE(round(sphere.GetVolume() * 1000) / 1000 == VOLUME_SPHERE);

	/*���������, ���������� ����� � �����*/
	REQUIRE(round(sphere.GetMass() * 1000) / 1000 == MASS_SPHERE);

	REQUIRE(sphere.ToString() == STRING_SPHERE);
};

/*��������������*/

const double DENSITY_PARALLELEPIPED = 30;
const double HEIGHT_PARALLELEPIPED = 3;
const double WIDTH_PARALLELEPIPED = 4;
const double DEPTH_PARALLELEPIPED = 5;
const double MASS_PARALLELEPIPED = 1800;
const double VOLUME_PARALLELEPIPED = 60;
const std::string STRING_PARALLELEPIPED = "Body type is parallelepiped. Massa is 1800. Volume is 60. Density is 30. Height is 3. Width is 4. Depth is 5.";

TEST_CASE("Check parallelepiped")
{
	CParallelepiped parallelepiped(DENSITY_PARALLELEPIPED, HEIGHT_PARALLELEPIPED, WIDTH_PARALLELEPIPED, DEPTH_PARALLELEPIPED);

	/*���������, ���� �� � ���� ���������*/
	REQUIRE(parallelepiped.GetDensity() == DENSITY_PARALLELEPIPED);

	/*���������, ���� �� � ��������������� ������*/
	REQUIRE(parallelepiped.GetHeight() == HEIGHT_PARALLELEPIPED);

	/*���������, ���� �� � ��������������� ������*/
	REQUIRE(parallelepiped.GetWidth() == WIDTH_PARALLELEPIPED);

	/*���������, ���� �� � ��������������� �������*/
	REQUIRE(parallelepiped.GetDepth() == DEPTH_PARALLELEPIPED);

	/*���������, ���������� ������ � �����*/
	REQUIRE(round(parallelepiped.GetVolume() * 1000) / 1000 == VOLUME_PARALLELEPIPED);

	/*���������, ���������� ����� � �����*/
	REQUIRE(round(parallelepiped.GetMass() * 1000) / 1000 == MASS_PARALLELEPIPED);

	REQUIRE(parallelepiped.ToString() == STRING_PARALLELEPIPED);
};

/*�������*/

const double DENSITY_CYLINDER = 30;
const double RADIUS_CYLINDER = 3;
const double HEIGHT_CYLINDER = 10;
const double MASS_CYLINDER = 8482.3;
const double VOLUME_CYLINDER = 282.743;
const std::string STRING_CYLINDER = "Body type is cylinder. Massa is 8482.3. Volume is 282.743. Density is 30. Base radius is 3. Height is 10.";

TEST_CASE("Check cylinder")
{
	CCylinder cylinder(DENSITY_CYLINDER, RADIUS_CYLINDER, HEIGHT_CYLINDER);

	REQUIRE(cylinder.GetDensity() == DENSITY_CYLINDER);

	/*���������, ���� �� � �������� ������*/
	REQUIRE(cylinder.GetBaseRadius() == RADIUS_CYLINDER);

	/*���������, ���� �� � �������� ������*/
	REQUIRE(cylinder.GetHeight() == HEIGHT_CYLINDER);

	/*���������, ���������� ������ � ��������*/
	REQUIRE(round(cylinder.GetVolume() * 1000) / 1000 == VOLUME_CYLINDER);

	/*���������, ���������� ����� � ��������*/
	REQUIRE(round(cylinder.GetMass() * 1000) / 1000 == MASS_CYLINDER);

	REQUIRE(cylinder.ToString() == STRING_CYLINDER);
};

/*�����*/

const double DENSITY_CONE = 30;
const double RADIUS_CONE = 3;
const double HEIGHT_CONE = 10;
const double MASS_CONE = 2827.433;
const double VOLUME_CONE = 94.248;
const std::string STRING_CONE = "Body type is cone. Massa is 2827.43. Volume is 94.248. Density is 30. Base radius is 3. Height is 10.";

TEST_CASE("Check cone")
{
	CCone cone(DENSITY_CONE, RADIUS_CONE, HEIGHT_CONE);

	/*���������, ���� �� � ������ ���������*/
	REQUIRE(cone.GetDensity() == DENSITY_CONE);

	/*���������, ���� �� � ������ ������*/
	REQUIRE(cone.GetBaseRadius() == RADIUS_CONE);

	/*���������, ���� �� � ������ ������*/
	REQUIRE(cone.GetHeight() == HEIGHT_CONE);

	/*���������, ���������� ������ � ������*/
	REQUIRE(round(cone.GetVolume() * 1000) / 1000 == VOLUME_CONE);

	/*���������, ���������� ����� � ������*/
	REQUIRE(round(cone.GetMass() * 1000) / 1000 == MASS_CONE);

	REQUIRE(cone.ToString() == STRING_CONE);
};

/*��������� ����*/

const double MASS_COMPOUND = 5192.92;
const double VOLUME_COMPOUND = 173.097;
const double DENSITY_COMPOUND = 30;
const std::string STRING_COMPOUND = "Body type is compound. Massa is 5192.92. Volume is 173.097. Density is 30. ""\n{""\nBody type is parallelepiped. Massa is 1800. Volume is 60. Density is 30. Height is 3. Width is 4. Depth is 5.""\nBody type is sphere. Massa is 3392.92. Volume is 113.097. Density is 30. Radius is 3.""\n}";

TEST_CASE("Check compound body")
{
	CCompound comp;

	/*���������, ���������� �����, ������ � ��������� � ������� ���������� ����*/
	REQUIRE(comp.GetDensity() == 0);
	REQUIRE(comp.GetMass() == 0);
	REQUIRE(comp.GetVolume() == 0);

	/*���������, ���������� �����, ������ � ��������� � ���������� ����*/
	REQUIRE(comp.AddChildBody(std::make_shared<CParallelepiped>(DENSITY_PARALLELEPIPED, HEIGHT_PARALLELEPIPED, WIDTH_PARALLELEPIPED, DEPTH_PARALLELEPIPED)));
	REQUIRE(comp.AddChildBody(std::make_shared<CSphere>(DENSITY_SPHERE, RADIUS_SPHERE)));

	REQUIRE(comp.ToString() == STRING_COMPOUND);

	REQUIRE(round(comp.GetMass() * 1000) / 1000 == MASS_COMPOUND);
	REQUIRE(round(comp.GetVolume() * 1000) / 1000 == VOLUME_COMPOUND);
	REQUIRE(round(comp.GetDensity() * 1000) / 1000 == DENSITY_COMPOUND);
}

TEST_CASE("recursive")
{
	/*��������, ������� ����������� ������ �� �������*/
	std::shared_ptr<CCompound> a = std::make_shared<CCompound>();
	std::shared_ptr<CCompound> b = std::make_shared<CCompound>();
	std::shared_ptr<CCompound> c = std::make_shared<CCompound>();
	std::shared_ptr<CCone> cone = std::make_shared<CCone>(DENSITY_CONE, RADIUS_CONE, HEIGHT_CONE);
	REQUIRE(a->AddChildBody(b));
	REQUIRE(b->AddChildBody(c));
	REQUIRE(!c->AddChildBody(a));
	REQUIRE(a->AddChildBody(cone));
	REQUIRE(!c->AddChildBody(cone));
	REQUIRE(!c->AddChildBody(c));
	double mass = a->GetMass();
}