/*! \file CQuadrilateral.h
	\brief Declaration of the general class Quadrilateral

	Details.
*/


#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

#include<iostream>

using namespace std;

/// @class Quadrilateral
/// @brief an abstract base class for quadrilateral
class Quadrilateral {
protected:

	float sides[4];
	
	void SetSides(float s1, float s2, float s3, float s4); 


public:

	/// @name CONSTRUCTORS/DESTRUCTOR
	/// @{
	Quadrilateral();
	Quadrilateral(const Quadrilateral &o);
	virtual ~Quadrilateral();
	/// @}
	
	/// @name OPERATORS
	/// @{
	Quadrilateral& operator=(const Quadrilateral &o); 
	bool operator==(const Quadrilateral &o);
	/// @}
	
	/// @name BASIC HANDLING
	/// @{
	void Init();												
	void Init(const Quadrilateral &o);							
	void Reset();												
	/// @}

			
	/// @name GETTERS
	/// @{
	float GetPerimeter();
	void GetSides(float &s0, float &s1, float &s2, float &s3);
	/// @}
	
	/// @name DEBUG and SERIALIZATION 
	/// @{
	void ErrorMessage(const char *string); 
	void WarningMessage(const char *string);
	void Dump();
	/// @}

};

#endif