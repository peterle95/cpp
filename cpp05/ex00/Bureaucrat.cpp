#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string& name, int _grade) : name(name) {
    if (_grade < 1) {
        throw _GradeTooHighException();
    }
    if (_grade > 150) {
        throw _GradeTooLowException();
    }
    this->_grade = _grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name) {
    *this = other;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
    if (this != &other) {
        this->_grade = other._grade;
    }
    return *this;
}

const std::string& Bureaucrat::getName() const {
    return this->name;
}

int Bureaucrat::get_Grade() const {
    return this->_grade;
}

void Bureaucrat::increment_Grade() {
    if (this->_grade - 1 < 1) {
        throw _GradeTooHighException();
    }
    this->_grade--;
}

void Bureaucrat::decrement_Grade() {
    if (this->_grade + 1 > 150) {
        throw _GradeTooLowException();
    }
    this->_grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat) {
    os << bureaucrat.getName() << ", bureaucrat _grade " << bureaucrat.get_Grade();
    return os;
}

const char* Bureaucrat::_GradeTooHighException::what() const throw() {
    return "_Grade too high";
}

const char* Bureaucrat::_GradeTooLowException::what() const throw() {
    return "_Grade too low";
}