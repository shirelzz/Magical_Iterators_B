#ifndef MAGICALCONTAINER_HPP
#define MAGICALCONTAINER_HPP

#include <vector>

namespace ariel {}

class MagicalContainer {

private:

    std::vector<int> elements;
    std::vector<int*> primePointers;

public:

    void addElement(int element);

    void removeElement(int element);

    std::size_t size() const { return elements.size(); }

    bool isPrime(int num);

    class AscendingIterator {

    private:

        MagicalContainer& container;
        std::vector<int>::iterator currentIndex;

        AscendingIterator(MagicalContainer &container, std::vector<int>::iterator index);

    public:

        // Default constructor
        AscendingIterator(MagicalContainer &container);

        // Copy constructor
        AscendingIterator(const AscendingIterator &other);

        // Move constructor (tidy)
        AscendingIterator(AscendingIterator&& other) noexcept;

        // Destructor
        ~AscendingIterator() = default;

        // Assignment operator
        AscendingIterator& operator=(const AscendingIterator& other);

        // Move assignment operator (tidy)
        AscendingIterator& operator=(AscendingIterator&& other) noexcept;

        // Equality comparison (operator==)
        bool operator==(const AscendingIterator& other) const;

        // Inequality comparison (operator!=)
        bool operator!=(const AscendingIterator& other) const;

        // Comparison operator (operator>)
        bool operator>(const AscendingIterator& other) const;

        // Comparison operator (operator<)
        bool operator<(const AscendingIterator& other) const;

        // Dereference operator (operator*)
        int& operator*() const;

        // Pre-increment operator (operator++)
        AscendingIterator& operator++();

        // begin(type) : Returns the appropriate iterator (ascending, cross, or prime)
        // pointing to the first element of the container based on the specified type.
        AscendingIterator begin();

        // end(type) : Returns the appropriate iterator (ascending, cross, or prime)
        // pointing one position past the last element of the container based on the specified type.
        AscendingIterator end();

    };

    class SideCrossIterator {

    private:

        MagicalContainer& container;
        std::vector<int>::iterator rightIndex;
        std::vector<int>::iterator leftIndex;
        bool half = false;
        bool first = true;

        SideCrossIterator(MagicalContainer &container, std::vector<int>::iterator right, std::vector<int>::iterator left);

    public:

        // Default constructor
        SideCrossIterator(MagicalContainer &container);

        // Copy constructor
        SideCrossIterator(const SideCrossIterator &other);

        // Move constructor (tidy)
        SideCrossIterator(SideCrossIterator&& other) noexcept;

        // Destructor
        ~SideCrossIterator() = default;

        // Assignment operator
        SideCrossIterator& operator=(const SideCrossIterator& other);

        // Move assignment operator (tidy)
        SideCrossIterator& operator=(SideCrossIterator&& other) noexcept;

        // Equality comparison (operator==)
        bool operator==(const SideCrossIterator& other) const;

        // Inequality comparison (operator!=)
        bool operator!=(const SideCrossIterator& other) const;

        // Comparison operator (operator>)
        bool operator>(const SideCrossIterator& other) const;

        // Comparison operator (operator<)
        bool operator<(const SideCrossIterator& other) const;

        // Dereference operator (operator*)
        int& operator*() const;

        // Pre-increment operator (operator++)
        SideCrossIterator& operator++();

        // begin(type) : Returns the appropriate iterator (ascending, cross, or prime)
        // pointing to the first element of the container based on the specified type.
        SideCrossIterator begin();

        // end(type) : Returns the appropriate iterator (ascending, cross, or prime)
        // pointing one position past the last element of the container based on the specified type.
        SideCrossIterator end();
    };

    class PrimeIterator {
    private:

        MagicalContainer& container;
        std::vector<int*>::iterator currentIndex;

        PrimeIterator(MagicalContainer &container, std::vector<int*>::iterator index);  

    public:

        // Default constructor
        PrimeIterator(MagicalContainer &container);

        // Copy constructor
        PrimeIterator(const PrimeIterator &other);

        // Move constructor (tidy)
        PrimeIterator(PrimeIterator&& other) noexcept;

        // Destructor
        ~PrimeIterator() = default;

        // Assignment operator
        PrimeIterator& operator=(const PrimeIterator& other);

        // Move assignment operator (tidy)
        PrimeIterator& operator=(PrimeIterator&& other) noexcept;

        // Equality comparison (operator==)
        bool operator==(const PrimeIterator& other) const;

        // Inequality comparison (operator!=)
        bool operator!=(const PrimeIterator& other) const;

        // Comparison operator (operator>)
        bool operator>(const PrimeIterator& other) const;

        // Comparison operator (operator<)
        bool operator<(const PrimeIterator& other) const;

        // Dereference operator (operator*)
        int& operator*() const;

        // Pre-increment operator (operator++)
        PrimeIterator& operator++();

        // begin(type) : Returns the appropriate iterator (ascending, cross, or prime)
        // pointing to the first element of the container based on the specified type.
        PrimeIterator begin();

        // end(type) : Returns the appropriate iterator (ascending, cross, or prime)
        // pointing one position past the last element of the container based on the specified type.
        PrimeIterator end();
    };


};

#endif
