/*
 *
 *  ________  _______    ___        ___   ________   ___   ________   ________   ________   _______    ________   ___
 * |\  _____\|\  ___ \  |\  \      |\  \ |\   ____\ |\  \ |\   ___ \ |\   __  \ |\   ___ \ |\  ___ \  |\   ____\ |\  \
 * \ \  \__/ \ \   __/| \ \  \     \ \  \\ \  \___| \ \  \\ \  \_|\ \\ \  \|\  \\ \  \_|\ \\ \   __/| \ \  \___|_\ \  \
 *  \ \   __\ \ \  \_|/__\ \  \     \ \  \\ \  \     \ \  \\ \  \ \\ \\ \   __  \\ \  \ \\ \\ \  \_|/__\ \_____  \\ \  \
 *   \ \  \_|  \ \  \_|\ \\ \  \____ \ \  \\ \  \____ \ \  \\ \  \_\\ \\ \  \ \  \\ \  \_\\ \\ \  \_|\ \\|____|\  \\ \__\
 *    \ \__\    \ \_______\\ \_______\\ \__\\ \_______\\ \__\\ \_______\\ \__\ \__\\ \_______\\ \_______\ ____\_\  \\|__|
 *     \|__|     \|_______| \|_______| \|__| \|_______| \|__| \|_______| \|__|\|__| \|_______| \|_______||\_________\   ___
 *                                                                                                       \|_________|  |\__\
 *                                                                                                                     \|__|
 */

#include <iostream>

class SamuxLifeExplained
{
public:
    /**
     * @param os: you can write it to a file stream to, if you find it romantic
     * enough to save a copy...
     */
    SamuxLifeExplained(std::ostream& os = std::cout) :
        _os(os)
    {}

    SamuxLifeExplained& One()
    {
        return tellMeBaby("one");
    }

    SamuxLifeExplained& More()
    {
        return tellMeBaby("more");
    }

    const SamuxLifeExplained& Day()
    {
        return tellMeBaby("day");
    }

    friend const SamuxLifeExplained& operator,(const SamuxLifeExplained& samux, int)
    {
        return samux.tellMeBaby(", one");
    }

    const SamuxLifeExplained& Fewer() const
    {
        return tellMeBaby("fewer");
    }

    const SamuxLifeExplained& Day() const
    {
        return tellMeBaby("day.");
    }

private:
    SamuxLifeExplained& tellMeBaby(const std::string& whaaaaaaat)
    {
        _os << whaaaaaaat << " ";
        return *this;
    }

    const SamuxLifeExplained& tellMeBaby(const std::string& whaaaaaaat) const
    {
        _os << whaaaaaaat << " ";
        return *this;
    }

    std::ostream& _os;
};

int One()
{
    return 42;
}

const SamuxLifeExplained& operator++(SamuxLifeExplained& samux)
{
    return (samux.One().More().Day(), One()).Fewer().Day();
}

int main()
{
    SamuxLifeExplained year;

    ++year;
}
