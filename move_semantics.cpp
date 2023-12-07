#include <iostream>
#include <string>

class String {

    char* m_data;
    uint32_t m_size;
public:
    String()
    {
        //default constructor
    }

    String(const char* c) {
        std::cout << "Created" << std::endl;
        m_size = strlen(c)+1;
        m_data = new char[m_size];
        memcpy(m_data, c, m_size);
    }
    //deep copy of objects
    String(const String& other) {
        std::cout << "Deep copied!" << std::endl;
        m_size = other.m_size;
        m_data = new char[m_size];
        memcpy(m_data, other.m_data, m_size);
    }

    String(String&& other) noexcept {
        std::cout << "Inside move function";
        m_data = other.m_data;
        m_size = other.m_size;

        other.m_data = nullptr;
        other.m_size = 0;
    }

    void print_Name()
    {
        std::cout<<std::endl;
        for (int i = 0;i < m_size;i++)
        {
            std::cout << m_data[i];
        }
        std::cout <<" *********************************** " << std::endl;
    }

    String& operator=(String&&s) noexcept
    {
        if (this != &s)
        {
            std::cout << "Inside operator overloaded function";
            delete[] m_data;
            m_data = s.m_data;
            m_size = s.m_size;

            s.m_data = nullptr;
            s.m_size = 0;
        }
        return *this;
    }

    ~String()
    {
        delete[] m_data;
        m_size = 0;
    }
};


int main()
{
    String S1 = "Narayanan";
    S1.print_Name();
    //Instead of deep copying, we will try to move the object
    String S2 = std::move(S1);
    S2.print_Name();
    S1.print_Name();

    //Now, lets try to overload assignment operator
    String a = "apple";
    a.print_Name();
    String b;
    b = std::move(a);
}

