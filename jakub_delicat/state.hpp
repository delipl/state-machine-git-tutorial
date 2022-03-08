#pragma once
#include <stdexcept>
#include <functional>
#include <initializer_list>
#include <memory>
#include <string>
#include <vector>

namespace dart_plus {

class StateException : public std::runtime_error {
   public:
    const char* what() {
        return what_message.c_str();
    }
    private:
     std::string what_message;
};

enum class StateStatus {
    unknown,
    error,
    enter,
    main,
    exit,
    stop
};


class State {
   public:
    State(const std::string &name, const std::function<StateStatus()> main, const std::function<StateStatus()> on_enter = nullptr, const std::function<StateStatus()> on_exit = nullptr, const std::function<StateStatus()> on_error = nullptr);
    StateStatus operator()();

   private:
    const std::string name;
    std::function<StateStatus()> main;
    std::function<StateStatus()> on_enter;
    std::function<StateStatus()> on_exit;
    std::function<StateStatus()> on_error;
    StateStatus status;
};
}  // namespace dart_plus
