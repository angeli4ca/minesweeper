/**
  @brief implementation of Clock class that works with the clock on the board
  @author Angelica Patsko
  @date 4/28/2016
*/

#include "clock.h"
#include <QTimer>

/**
 * @brief Clock::Clock constructor
 * @param parent - used for memory management (Clock will be added to param's cildren list and will be deleted with param)
 */
Clock::Clock(QWidget *parent): QLCDNumber(parent), m_time(0, 0, 0) {
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(on_tick()));
    m_timer->start(1000);
    display(m_time.toString("hh:mm:ss"));
    setFixedSize(100, 30);
}

/**
 * @brief Clock::on_tick - slot for processing timer's signal
 */
void Clock::on_tick() {
    m_time = m_time.addSecs(1);
    display(m_time.toString("hh:mm:ss"));
}


/**
 * @brief Clock::stop - slot for stopping the timer
 */
void Clock::stop() {
    m_timer->stop();
}
