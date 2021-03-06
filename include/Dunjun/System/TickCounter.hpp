#ifndef DUNJUN_SYSTEM_TICKCOUNTER_HPP
#define DUNJUN_SYSTEM_TICKCOUNTER_HPP

#include <Dunjun/System/Clock.hpp>

namespace Dunjun
{
class TickCounter
{
public:
	bool update(Time period)
	{
		bool reset{false};
		if (m_clock.getElapsedTime() >= period)
		{
			m_tickRate = m_tick * (1.0f / period.asSeconds());
			m_tick = 0;
			reset = true;
			m_clock.restart();
		}

		m_tick++;

		return reset;
	}

	inline f64 getTickRate() const { return m_tickRate; }

private:
	usize m_tick{0};
	f64 m_tickRate{0};
	Clock m_clock{};
};

} // namespace Dunjun

#endif
