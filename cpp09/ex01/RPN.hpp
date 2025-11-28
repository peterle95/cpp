#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>

# define TOKEN_SPLIT 1

class RPN {
private:
    std::stack<int> _stack;
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);

public:
    RPN();
    ~RPN();

    void execute(const std::string& expression);
};

#endif