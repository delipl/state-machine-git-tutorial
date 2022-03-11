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
    State(const std::size_t id, const std::string& name);
    StateStatus operator()();
    size_t get_next_state_id() const;

   private:
    const std::size_t id;
    const std::string name;
    virtual StateStatus main() = 0;
    virtual StateStatus on_enter();
    virtual StateStatus on_error();
    virtual StateStatus on_exit();
    size_t next_state_id = 0;
    StateStatus status;
};
}  // namespace dart_plus
