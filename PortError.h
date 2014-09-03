#ifndef PORTERROR_H
#define PORTERROR_H

#include <stdexcept>
#include <string>

class PortError : public std::runtime_error
{
public:
    PortError( const std::string &errorText ) : std::runtime_error( "" )
    {
        m_message = errorText;
    }

    virtual ~PortError() throw()
    {

    }

    virtual const char *what() const throw()
    {
        return m_message.c_str();
    }

    std::string getMessage()
    {
        return m_message;
    }

private:
    std::string m_message;
};

#endif // PORTERROR_H
