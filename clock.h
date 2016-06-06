/**
  @brief declaration of CLock class derived from QLSDNumber that works with the clock on the board
  @author Angelica Patsko
  @date 4/28/2016
*/

#ifndef CLOCK_H
# define CLOCK_H
# include <QLCDNumber>
# include <QTime>

/**
 * @brief The Clock class for displaying time on the board
 */
class Clock: public QLCDNumber {
    Q_OBJECT

public:
  Clock(QWidget *parent = 0);

private slots:
  void on_tick();
  void stop();

protected:
  //current time
  QTime m_time;

  //timer
  QTimer *m_timer;
};

#endif // CLOCK_H
