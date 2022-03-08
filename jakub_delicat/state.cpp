#include "state.hpp"
namespace dart_plus {
State::State(const std::string &name, const std::function<StateStatus()> main, const std::function<StateStatus()> on_enter, const std::function<StateStatus()> on_exit, const std::function<StateStatus()> on_error)
    : name{name}, main{main}, on_enter{on_enter}, on_exit{on_exit}, on_error{on_error}{
    status = on_enter == nullptr ? StateStatus::main : StateStatus::enter;
}

StateStatus State::operator()() {
    try {
        switch (status) {
            case StateStatus::unknown:
                throw std::runtime_error("[StateStatus] Unknown StateStatus!!!");
                break;
            case StateStatus::enter:
                if (on_enter == nullptr) {
                    throw std::runtime_error("[StateStatus] The enter handler does not exists. Try to make on_enter() function.");
                } 
                status = on_enter();
                break;
            case StateStatus::main:
                status = main();
                break;
            case StateStatus::exit:
                if (on_exit == nullptr) {
                    throw std::runtime_error("[StateStatus] The exit handler does not exists. Try to make on_exit() function.");
                }
                status = on_exit();
                break;
            case StateStatus::error:
                if (on_error == nullptr) {
                    throw std::runtime_error("[StateStatus] The error handler does not exists. Try to make on_error() function.");
                }
                status = on_error();
                break;
            default:
                throw std::runtime_error("[StateStatus] Default error case.");
                break;
        }
    } catch (StateException &e) {
        status = StateStatus::error;
    }
    return status;
};
}  // namespace dart_plus