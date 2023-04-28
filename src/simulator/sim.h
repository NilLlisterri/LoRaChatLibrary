#pragma once

#include <Arduino.h>

#include <ArduinoLog.h>

#include "wifi/wifiServerService.h"

#include "message/messageService.h"

#include "message/messageManager.h"

#include "simCommandService.h"

#include "simMessage.h"

#include "LoraMesher.h"

#include "sensor/temperature-onewire/temperature.h"

#include "sensor/dht22/dht22.h"

class Sim: public MessageService {
public:
    /**
     * @brief Construct a new GPSService object
     *
     */
    static Sim& getInstance() {
        static Sim instance;
        return instance;
    }

    SimCommandService* simCommandService = new SimCommandService();

    SimulatorService* service = nullptr;

    void init();

    String start();

    String stop();

    String getJSON(DataMessage* message);

    DataMessage* getDataMessage(JsonObject data);

    void processReceivedMessage(messagePort port, DataMessage* message);

private:
    Sim(): MessageService(SimApp, "Sim") {
        commandService = simCommandService;
    };

    TaskHandle_t sim_TaskHandle = NULL;

    void createSimTask();

    static void simLoop(void*);

    bool running = false;

    void sendAllData();

    SimMessage* createSimMessage(LM_State* state);
};