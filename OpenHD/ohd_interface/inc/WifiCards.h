#ifndef WIFI_H
#define WIFI_H

#include <array>
#include <chrono>
#include <vector>

#include <boost/asio.hpp>
#include <boost/bind.hpp>

#include "json.hpp"

#include "openhd-wifi.hpp"

/**
 * Provides access to the discovered wifi cards on the system.
 * There should only be one instance of this class in the whole OpenHD project.
 */
class WifiCards {
public:
    WifiCards(bool is_air, std::string unit_id);
    virtual ~WifiCards() = default;
    void process_manifest();
    void configure();
    void setup_hotspot(const WiFiCard &card);
    static bool set_card_state(const WiFiCard& card, bool up);
    static bool set_frequency(const WiFiCard& card, const std::string& frequency);
    static bool set_txpower(const WiFiCard& card, const std::string& txpower);
    static bool enable_monitor_mode(const WiFiCard& card);
    static void save_settings(const std::vector<WiFiCard>& cards, const std::string& settings_file);
private:
    // Setup the wifi card for its intended use case.
    // Note that his method does not modify any member of the WifiCard class,
    // Since after it has been executed the actual state of the wifi card should match
    // the specified state of WifiCard by its struct members.
    void setup_card(const WiFiCard &card);
private:
    const std::string m_unit_id;
    const bool m_is_air = false;
    std::vector<WiFiCard> m_wifi_cards;
    // todo: read from settings file once new settings system merged
    std::string m_wifi_hotspot_address = "192.168.2.1";
    std::string m_wifi_hotspot_txpower = "3100";
    std::string m_default_5ghz_frequency = "5180";
    std::string m_default_2ghz_frequency = "2412";
};

#endif

