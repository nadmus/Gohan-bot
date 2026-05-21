/*
 * SCTimer.h
 *
 *  Created on: May 19, 2026
 *      Author: Nadir Mustafa
 */

#ifndef HARDWARE_PERIFERICOS_SCTIMER_SCTIMER_H_
#define HARDWARE_PERIFERICOS_SCTIMER_SCTIMER_H_

#include "Pin.h"
#include "LPC845.h"
#include "tipos.h"

class SCTimer{
private:
	static constexpr uint32_t MATCHSEL = 0;
	static constexpr uint32_t MATCH_ONLY=(1 << 12);
	static constexpr uint32_t IOCOND_POS=10;
	static constexpr uint32_t STATE_EVENT_ALL=0xFFFFFFFF;

public:
	enum input_t {INPUT0=0,INPUT1,INPUT2,INPUT3,INPUT4,INPUT5};
	enum output_t {OUTPUT0=0,OUTPUT1,OUTPUT2,OUTPUT3,OUTPUT4,OUTPUT5,OUTPUT6,OUTPUT7};

	enum edge_t {LOW=0, RISE, FALL, HIGH};
	enum Event_type {Input,Output};

	typedef enum match_t {MATCH1=0,MATCH2,MATCH3,MATCH4,MATCH5,MATCH6,MATCH7,MATCH8}match_t;
	typedef enum capture_t {CAPTURE1=0,CAPTURE2,CAPTURE3,CAPTURE4,CAPTURE5,CAPTURE6,CAPTURE7,CAPTURE8}capture_t;
	typedef enum event_t {EVENT1=0, EVENT2,EVENT3,EVENT4,EVENT5,EVENT6,EVENT7,EVENT8}event_t;

	enum mode_t {match,capture};
	enum Event_Type {input,output};




private:

	Event_Type event_type[8];


public:
	SCTimer();
	void setUnify(bool a);
	void setAutoLimit(bool a);
	void StartTimer(void);
	void StopTimer(void);


	void SetMatch(uint32_t ms, match_t match);
	void CreateMatchEvent(match_t match,event_t event);

	void CreateInputEvent(event_t event, edge_t edge);
	void SetCapture(capture_t capture, event_t event);

	void SetOutput(output_t out, event_t event);
	void ClrOutput(output_t out, event_t event);

	void ConfigSwitchMatrixSCTOut(uint8_t port, uint8_t bit,uint8_t out_number);

	virtual ~SCTimer();
};

#endif /* HARDWARE_PERIFERICOS_SCTIMER_SCTIMER_H_ */
