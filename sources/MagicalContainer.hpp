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

    void removeElement(int element); // index?

    std::size_t size() const { return elements.size(); }

    bool isPrime(int num);

    // int get(int index);


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

        // begin(type)
        AscendingIterator begin();

        // end(type)
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

        // begin(type)
        SideCrossIterator begin();

        // end(type)
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

        // begin(type)
        PrimeIterator begin();

        // end(type)
        PrimeIterator end();
    };


};

/**

operations for each iterator:
• Default constructor
• Copy constructor
• Destructor
• Assignment operator
• Equality comparison (operator==)
• Inequality comparison (operator!=)
• GT, LT comparison (operator>, operator<) all comparison operators only valid for iterators of the same type of order
  and should compare the location of the iterator in the container and not the element inside. Example bellow.
  Using operators on iterators of different type or different containers should throw an examtion.
• Dereference operator (operator*)
• Pre-increment operator (operator++)
• begin(type): Returns the appropriate iterator (ascending, cross, or prime) pointing to the first element
  of the container based on the specified type.
• end(type): Returns the appropriate iterator (ascending, cross, or prime) pointing one position past the last element
  of the container based on the specified type.

 Example: say our container contains the numbers 1,2,4,5,14 the iterators will return the elements
 in the following order:
• Ascending: 1,2,4,5,14. operator> should return true on 5>2, 14>1
• prime: 2,5. operator> should return true on 5>2
• cross: 1,14,2,5,4 (one from the start then one from the end). operator> should return true on 5>14, 2>1, 4>14

All iterators should work in O(1) in both memory and time complexity.
Iterators should NOT be detached from the main container.
If one adds an element to a container after an iterator is created,
the iterator should know the element return it should its turn will come.

 */

#endif
