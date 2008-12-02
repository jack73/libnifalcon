/***
 * @file FalconKinematic.h
 * @brief Base class for falcon kinematic classes 
 * @author Kyle Machulis (kyle@nonpolynomial.com) / Kevin Ouellet (kouellet@users.sourceforge.net)
 * @version $Id$
 * @copyright (c) 2007-2008 Nonpolynomial Labs/Kyle Machulis
 * @license BSD License
 *
 * $HeadURL$
 * 
 * Project info at http://libnifalcon.sourceforge.net/ 
 *
 */
#ifndef FALCONKINEMATIC_H
#define FALCONKINEMATIC_H

#include <stdint.h>
#include <iostream>

#include "falcon/core/FalconCore.h"
#include "falcon/core/FalconGeometry.h"

namespace libnifalcon
{
	class FalconKinematic : public FalconCore
	{
	public:
		struct WorkspaceBounds
		{
			double X[2];
			double Y[2];
			double Z[2];
		};
		enum {
			FALCON_KINEMATIC_OUT_OF_RANGE = 5000
		};
		FalconKinematic() { }
		~FalconKinematic() { }
		float getTheta(int16_t encoder_value)
		{
			return (((SHAFT_DIAMETER*PI) / (WHEEL_SLOTS_NUMBER*4)) * (encoder_value))/((PI*SMALL_ARM_DIAMETER)/360.0f) + THETA_OFFSET_ANGLE;
		}
		virtual bool getForces(double position[3], double cart_force[3], int16_t (&enc_force)[3]) = 0;
		virtual bool getAngles(double position[3], double angles[3]) = 0;
		virtual bool getPosition(int16_t encoders[3], double position[3]) = 0;
		void setWorkspaceBounds(WorkspaceBounds b) { m_workspaceBounds = b; }
		WorkspaceBounds getWorkspaceBounds() {return m_workspaceBounds;}
	protected:
		//Bounds for the x, y, and z axis
		WorkspaceBounds m_workspaceBounds;
	};
}

#endif
