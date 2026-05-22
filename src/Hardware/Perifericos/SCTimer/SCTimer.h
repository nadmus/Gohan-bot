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
	static constexpr uint32_t OUTSEL_POS=5;
	static constexpr uint32_t IOSEL_POS = 6;
	static constexpr uint32_t IOCOND_POS=10;
	static constexpr uint32_t STATE_EVENT_ALL=0xFFFFFFFF;
	static constexpr uint32_t MAX_EVENTS=8;

	static constexpr uint32_t INPUT_SELECT=(0 << OUTSEL_POS);
	static constexpr uint32_t OUTPUT_SELECT=(1 << OUTSEL_POS);


public:
	enum input_t {INPUT0=0,INPUT1,INPUT2,INPUT3};
	enum output_t {OUTPUT0=0,OUTPUT1,OUTPUT2,OUTPUT3,OUTPUT4,OUTPUT5,OUTPUT6};

	enum edge_t {LOW=0, RISE, FALL, HIGH};

	enum EventSource {UNUSED, MATCH, INPUT, OUTPUT};

	typedef enum match_t {MATCH0=0,MATCH1,MATCH2,MATCH3,MATCH4,MATCH5,MATCH6,MATCH7}match_t;
	typedef enum capture_t {CAPTURE0=0,CAPTURE1,CAPTURE2,CAPTURE3,CAPTURE4,CAPTURE5,CAPTURE6,CAPTURE7}capture_t;
	typedef enum event_t {EVENT0=0, EVENT1,EVENT2,EVENT3,EVENT4,EVENT5,EVENT6,EVENT7}event_t;

	enum mode_t {match,capture};
	//enum Event_Type {input,output};




private:

	EventyType event_type[8];



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

	uint32_t ReadCapture(capture_t capture);

	void SetOutput(output_t out, event_t event);
	void ClrOutput(output_t out, event_t event);

	void ConfigSwitchMatrixSCTOut(uint8_t port, uint8_t bit,uint8_t out_number);

	virtual ~SCTimer();
};

#endif /* HARDWARE_PERIFERICOS_SCTIMER_SCTIMER_H_ */
