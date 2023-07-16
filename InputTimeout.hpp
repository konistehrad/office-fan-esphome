#include "esphome.h"

class InputTimeout : public Component {
    private:
        uint32_t m_timeoutMs;
        uint32_t m_lastTime;
    public:
        InputTimeout(uint32_t timeoutMs) : m_timeoutMs(timeoutMs) {}
        void setup() override {
            m_lastTime = millis();
        }
        void loop() override { }
        void touch() { m_lastTime = millis(); }
        bool get_timeout_has_expired() {
            return millis() - m_lastTime > m_timeoutMs;
        }
};
