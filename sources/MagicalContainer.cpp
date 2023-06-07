# include "MagicalContainer.hpp"
# include <iostream>
# include <cmath>
# include <algorithm>
# include <vector>

using namespace std;
using namespace ariel;


void MagicalContainer::addElement(int element)
{
    // Add element at the end
    if (elements.size() == 0)
    {
        elements.push_back(element);
    }

    // Add element at the end
    // elements.push_back(element);

    // Sort elements after addition
    // std::sort(elements.begin(), elements.end());
    else{
        for ( std::vector<int>::iterator i = elements.begin() ; i < elements.end(); ++i)
        {
            if (element <= *(i))
            {
                elements.insert(i, element);
                break;  // Inserted the element, so exit the loop
            }
        }
    // If the element is greater than all existing elements, insert at the end
    if (element > elements.back())
    {
        elements.push_back(element);
    }
    }
    

    if (isPrime(element))
    {
        int *pelement = new int(element);
        primePointers.push_back(pelement);
    }
    
}

void MagicalContainer::removeElement(int element)
{
   // Check if the element exists in elements
    auto elementIter = std::find(elements.begin(), elements.end(), element);

    if (elementIter == elements.end())
    {
        throw std::runtime_error("Element not found");
    }

    if (elementIter != elements.end())
    { // Meaning it exists

        // Check if the element exists in primePointers
        auto primeIter = std::find(primePointers.begin(), primePointers.end(), &(*elementIter));

        if (primeIter != primePointers.end())
        {
            // Remove the element from primePointers and delete the integer pointer
            primePointers.erase(primeIter);
            delete *primeIter;
        }

        // Remove the element from elements
        elements.erase(elementIter);
    }
}

bool MagicalContainer::isPrime(int num)
{
    if (num < 2)
    {
        return false;
    }

    for (int i = 2; i <= std::sqrt(num); ++i)
    {
       if (num % i == 0)
       {
            return false;
        }
    }

    return true;
}


/**
 --------------------- AscendingIterator ---------------------
*/

MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container,  std::vector<int>::iterator index)
: container(container), currentIndex(index) {}


MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer &container)
: container(container), currentIndex(container.elements.begin()) 
{
}

MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer::AscendingIterator &other)
: container(other.container), currentIndex(other.currentIndex) {}

// tidy
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer::AscendingIterator &&other) noexcept
: container(other.container), currentIndex(other.currentIndex) {}

MagicalContainer::AscendingIterator
&MagicalContainer::AscendingIterator::operator=(const MagicalContainer::AscendingIterator &other)
{
    if (this != &other)
    {
        if (typeid(&other) != typeid(this))
        {
            throw std::runtime_error("Iterators are pointing at different containers");
        }

        container = other.container;
        currentIndex = other.currentIndex;
    }
    return *this;
}

// tidy
MagicalContainer::AscendingIterator
&MagicalContainer::AscendingIterator::operator=(MagicalContainer::AscendingIterator &&other) noexcept
{
    if (this != &other)
    {
        container = other.container;
        currentIndex = other.currentIndex;
    }
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const MagicalContainer::AscendingIterator &other) const
{
    return currentIndex == other.currentIndex;
}

bool MagicalContainer::AscendingIterator::operator!=(const MagicalContainer::AscendingIterator &other) const
{
    return !(*this == other);
}

bool MagicalContainer::AscendingIterator::operator>(const MagicalContainer::AscendingIterator &other) const
{
    return currentIndex > other.currentIndex;
}

bool MagicalContainer::AscendingIterator::operator<(const MagicalContainer::AscendingIterator &other) const
{
    return currentIndex < other.currentIndex;
}

int& MagicalContainer::AscendingIterator::operator*() const
{
    return *currentIndex;
}

MagicalContainer::AscendingIterator &MagicalContainer::AscendingIterator::operator++()
{
    if (currentIndex == container.elements.end())
    {
        throw std::runtime_error("Iterator increment beyond end");
    }
    
    ++currentIndex;
    return *this;
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin()
{
    return AscendingIterator(container, container.elements.begin());
}

MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end()
{
    return AscendingIterator(container, container.elements.end());
}

/**
 --------------------- SideCrossIterator ---------------------
*/

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container, std::vector<int>::iterator right, std::vector<int>::iterator left)
: container(container), rightIndex(right), leftIndex(left) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer &container)
: container(container), rightIndex(container.elements.end() - 1), leftIndex(container.elements.begin())
{
    if (container.elements.empty())
    {
        rightIndex = container.elements.begin();
        leftIndex = container.elements.end();   
 }
    
}

MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer::SideCrossIterator &other)
: container(other.container), rightIndex(other.rightIndex), leftIndex(other.leftIndex) {}

// tidy
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer::SideCrossIterator &&other) noexcept
: container(other.container), rightIndex(other.rightIndex), leftIndex(other.leftIndex) {}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator=(const MagicalContainer::SideCrossIterator &other)
{
    if (this != &other)
    {
        if (typeid(&other) != typeid(this))
        {
            throw std::runtime_error("Iterators are pointing at different containers");
        }

        container = other.container;
        rightIndex = other.rightIndex;
        leftIndex = other.leftIndex;
    }
    return *this;
}

// tidy
MagicalContainer::SideCrossIterator
&MagicalContainer::SideCrossIterator::operator=(MagicalContainer::SideCrossIterator &&other) noexcept
{
    if ((this != &other))
    {        
        container = other.container;
        rightIndex = other.rightIndex;
        leftIndex = other.leftIndex;
    }
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const MagicalContainer::SideCrossIterator &other) const
{
    return (rightIndex == other.rightIndex) && (leftIndex == other.leftIndex);
}

bool MagicalContainer::SideCrossIterator::operator!=(const MagicalContainer::SideCrossIterator &other) const
{
    return !(*this == other);
}

bool MagicalContainer::SideCrossIterator::operator>(const MagicalContainer::SideCrossIterator &other) const
{
    return (leftIndex > other.leftIndex) && (rightIndex < other.rightIndex) ||
            (leftIndex > other.leftIndex) && (rightIndex <= other.rightIndex) ||
            (leftIndex >= other.leftIndex) && (rightIndex < other.rightIndex);
}

bool MagicalContainer::SideCrossIterator::operator<(const MagicalContainer::SideCrossIterator &other) const
{
    return (leftIndex < other.leftIndex) && (rightIndex > other.rightIndex) ||
            (leftIndex < other.leftIndex) && (rightIndex > other.rightIndex) ||
            (leftIndex < other.leftIndex) && (rightIndex > other.rightIndex);
}

int& MagicalContainer::SideCrossIterator::operator*() const
{
    
    // if (leftIndex == rightIndex)
    // {
    //     return *leftIndex;
    // }
    // else 

    // if (leftIndex - container.elements.begin() >= container.elements.end() - rightIndex)
    // {
    //     return *rightIndex;
    // }
    // else
    // {
    //     return *leftIndex;
    // }

    if (leftIndex == rightIndex)
    {
        return *leftIndex;
    }
    else if (leftIndex - container.elements.begin() >= container.elements.end() - rightIndex)
    {
        return *rightIndex;
    }
    else
    {
        return *leftIndex;
    }
}

MagicalContainer::SideCrossIterator &MagicalContainer::SideCrossIterator::operator++()
{
    if (half)
    {
        throw std::runtime_error("Iterator increment beyond end");
    }
    if (leftIndex == rightIndex)
    {
        half = true;
    }

    if ((leftIndex - container.elements.begin() >= container.elements.end() - rightIndex) &&
        (rightIndex != container.elements.begin()) && !(half))
    {
        --rightIndex;
    }
    else if ((leftIndex - container.elements.begin() <= container.elements.end() - rightIndex) &&
             (leftIndex != container.elements.end() && !(half)))
    {
        ++leftIndex;
    }
    if (half)
    {
        leftIndex = container.elements.end();
        rightIndex = container.elements.begin();
    }
    
    return *this;

    // ggggggg
    // if (leftIndex == rightIndex && !half)
    // {
    //     leftIndex = container.elements.end();
    //     rightIndex = container.elements.begin();
    //     half = true;
    // }
    // else if (leftIndex - container.elements.begin() >= container.elements.end() - rightIndex)
    // {
    //     --rightIndex;
    // }
    // else
    // {
    //     ++leftIndex;
    // }
    
    // return *this;

}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin()
{
    if (container.elements.empty())
    {
        return this->end();
    }
    
    return SideCrossIterator(container, container.elements.end()-1, container.elements.begin());
}

MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end()
{
    return SideCrossIterator(container, container.elements.begin(), container.elements.end());
}


/**
 --------------------- PrimeIterator ---------------------:
*/

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container, std::vector<int*>::iterator index)
: container(container), currentIndex(index) {}

MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer &container)
: container(container), currentIndex(container.primePointers.begin()) {}

MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer::PrimeIterator &other)
: container(other.container), currentIndex(other.currentIndex) {}

// tidy
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer::PrimeIterator &&other) noexcept
: container(other.container), currentIndex(other.currentIndex) {}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator=(const MagicalContainer::PrimeIterator &other)
{
    if (this != &other)
    {
        if (typeid(&other) != typeid(this))
        {
            throw std::runtime_error("Iterators are pointing at different containers");
        }

        container = other.container;
        currentIndex = other.currentIndex;
    }
    return *this;}

// tidy
MagicalContainer::PrimeIterator
&MagicalContainer::PrimeIterator::operator=(MagicalContainer::PrimeIterator &&other) noexcept
{
    if (this != &other)
    {
        container = other.container;
        currentIndex = other.currentIndex;
    }
    return *this;}

bool MagicalContainer::PrimeIterator::operator==(const MagicalContainer::PrimeIterator &other) const
{
    return currentIndex == other.currentIndex;
}

bool MagicalContainer::PrimeIterator::operator!=(const MagicalContainer::PrimeIterator &other) const
{
    return !(*this == other);
}

bool MagicalContainer::PrimeIterator::operator>(const MagicalContainer::PrimeIterator &other) const
{
    return currentIndex > other.currentIndex;
}

bool MagicalContainer::PrimeIterator::operator<(const MagicalContainer::PrimeIterator &other) const
{
    return currentIndex < other.currentIndex;
}

int& MagicalContainer::PrimeIterator::operator*() const
{
    return **currentIndex;
}

MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++()
{
    if (currentIndex == container.primePointers.end())
    {
        throw std::runtime_error("Iterator increment beyond end");
    }

    ++currentIndex;
    return *this;
}

MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin()
{    
    return PrimeIterator(container, container.primePointers.begin());
}


MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end()
{
    return PrimeIterator(container, container.primePointers.end());
}