/*
 * Regulator.c
 *
 *  Created on: Jan 17, 2022
 *      Author: anton
 */
#include <Regulator.h>

	/**
	 * @brief Initialize PID instance
	 * @param[in] *PID PID instance to initialize
	 * @return None
	 */
void PID_init(arm_pid_instance_f32 *PID)
{
	PID->Kd=KD/Tp;
	PID->Ki=KI*Tp;
	PID->Kp=KP;
	arm_pid_init_f32(PID, 0);
}

/**
 * @brief Compute new control signal
 * @param[in] *PID PID instance
 * @param[in] e error value
 * @return control signal value
 */
int Regulation(arm_pid_instance_f32 *PID,uint16_t e)
{
	float static u;
	if(abs(e)>50)
	{
	u=arm_pid_f32(PID,e);
	if(u<-500)u=-500;
	if(u>500)u=500;
	}
	return u+1500;
}