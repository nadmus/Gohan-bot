/*******************************************************************************************************************************//**
 *
 * @file		PerifericoTemporizado.h
 * @brief		Breve descripción del objetivo del Módulo
 * @date		Jun 11, 2024
 * @author
 *
 **********************************************************************************************************************************/

#ifndef PERIFTEMP_PERIFERICOTEMPORIZADO_H_
#define PERIFTEMP_PERIFERICOTEMPORIZADO_H_


class PerifericoTemporizado {
private:
	void (*m_HandlerDelPeriferico)(void);
public:
	PerifericoTemporizado (void (*CallBack)(void) = nullptr);
    virtual void handlerDelPeriferico();
    virtual ~PerifericoTemporizado() ;
};

#endif /* PERIFTEMP_PERIFERICOTEMPORIZADO_H_ */
