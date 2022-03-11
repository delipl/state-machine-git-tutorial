#include "state.hpp"
namespace dart_plus {
State::State(const std::size_t id, const std::string& name)
    : id{id}, name{name} {}

StateStatus State::on_enter() {
    throw std::runtime_error("[StateStatus] The enter handler does not exists. Try to make on_enter() function.");
    return StateStatus::unknown;
}

StateStatus State::on_error() {
    throw std::runtime_error("[StateStatus] The error handler does not exists. Try to make on_error() function.");
    return StateStatus::unknown;
}

StateStatus State::on_exit() {
    throw std::runtime_error("[StateStatus] The exit handler does not exists. Try to make on_exit() function.");
    return StateStatus::unknown;
}

StateStatus State::operator()() {
    try {
        switch (status) {
            case StateStatus::unknown:
                throw std::runtime_error("[StateStatus] Unknown StateStatus!!!");
                break;
            case StateStatus::enter:
                status = on_enter();
                break;
            case StateStatus::main:
                status = main();
                break;
            case StateStatus::exit:
                status = on_exit();
                break;
            case StateStatus::error:
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

size_t State::get_next_state_id() const{
    return next_state_id;
}
}  // namespace dart_plus