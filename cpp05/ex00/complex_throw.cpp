#include <iostream>
#include <exception>
#include <string>

class DatabaseError : public std::exception {
private:
    std::string message;
    
public:
    DatabaseError(const std::string& msg) : message(msg) {}
    
    // Using throw() specification - promises to not throw exceptions
    virtual const char* what() const throw() {
        return message.c_str();
    }
    
    // Destructor should also not throw
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