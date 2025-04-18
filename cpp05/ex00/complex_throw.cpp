#include <iostream>
#include <exception>
#include <string>

class DatabaseError : public std::exception // Your DatabaseError class inherits from std::exception.
/*he base class std::exception provides a virtual function called what(). 
The purpose of what() is to return a C-style string (const char*) that describes the exception.
By default, the message from std::exception::what() is usually very generic 
(implementation-defined, might just be "std::exception").*/
{
private:
    std::string message;
    
public:
    /*Your DatabaseError class is designed to represent specific database errors. 
    It stores a custom error message (std::string message) passed to its constructor.*/
    DatabaseError(const std::string& msg) : message(msg) {}
    
    // Using throw() specification - promises to not throw exceptions
    /*To make your custom exception useful, you need to override the what() method so 
    that when someone catches a DatabaseError, they can call what() and get your specific error 
    message (e.g., "Empty server name provided") instead of the generic base class message.*/
    virtual const char* what() const throw() 
    /*throw() is an older C++ feature called a dynamic exception specification. It's a promise added 
    to a function's signature that the function will not allow any exceptions to escape from it.
    (Important Note: Dynamic exception specifications like throw() and throw(SomeType) are 
    deprecated in C++11 and removed in C++17. The modern way to indicate a function doesn't throw is noexcept.)*/
    {
        /*Inside your overridden what(), message.c_str() 
        converts the internal std::string into the const char* required by the function's signature.*/
        return message.c_str();
        /*Why use throw() (or noexcept) on what()?
        Inheritance Contract: The base class function std::exception::what() is declared with throw() 
        (or noexcept(true) in modern C++). When you override a virtual function, you cannot weaken its
         exception guarantee. Since the base class promises not to throw from what(), your derived 
         class override must also promise not to throw.
        Safety During Error Handling: This is the critical reason. Imagine you are already handling an 
        exception inside a catch block. You call e.what() to log the error or display it. What happens 
        if what() itself could throw another exception? This could lead to nested exception handling 
        problems or even program termination (calling std::terminate). Error reporting functions must 
        be safe and reliable; they shouldn't cause more errors while trying to report the first one. 
        The throw() (or noexcept) guarantee makes what() safe to call even during complex error 
        recovery or stack unwinding.*/
    }
    
    /*Why use throw() (or noexcept) on the Destructor ~DatabaseError()?
    Stack Unwinding Safety: When an exception is thrown, the program unwinds the stack, calling destructors 
    for all local objects that are going out of scope. If a destructor were to throw an 
    exception while the stack is already unwinding due to another exception, C++ 
    considers this an unrecoverable situation and calls std::terminate(), aborting the program immediately.
    Rule: Destructors should never allow exceptions to propagate out. Adding throw() 
    (or noexcept in C++11 onwards, which is the default for destructors) explicitly 
    states and enforces this crucial safety rule.*/
    virtual ~DatabaseError() throw() {}
};

class Database {
public:
    void connect(const std::string& server) {
        if (server.empty()) {
            throw DatabaseError("Empty server name provided");
        }
        std::cout << "Connected to " << server << std::endl;
    }
    
    // This function specifies it might throw DatabaseError
    void query(const std::string& sql) throw(DatabaseError) {
        if (sql.empty()) {
            throw DatabaseError("Empty SQL query");
        }
        std::cout << "Executing: " << sql << std::endl;
    }
};

int main() {
    Database db;
    
    try {
        db.connect("production-server");
        db.query("");  // This will throw an exception
    } catch (const DatabaseError& e) {
        std::cout << "Database error: " << e.what() << std::endl;
    }
    
    return 0;
}