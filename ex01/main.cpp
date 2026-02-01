#include <iostream>
#include "Serializer.hpp"

int main()
{
    // 1️⃣ Create real data
    Data original;
    original.id = 42;
    original.name = "Malak";

    // 2️⃣ Pointer to the data
    Data* ptr = &original;

    std::cout << "Original pointer address: " << ptr << std::endl;
    std::cout << "Original data -> id: " << ptr->id
              << ", name: " << ptr->name << std::endl;

    std::cout << "\n--- SERIALIZING ---\n";

    // 3️⃣ Convert pointer → integer
    uintptr_t raw = Serializer::serialize(ptr);
    std::cout << "Serialized value (uintptr_t): " << raw << std::endl;

    std::cout << "\n--- DESERIALIZING ---\n";

    // 4️⃣ Convert integer → pointer
    Data* restored = Serializer::deserialize(raw);

    std::cout << "Restored pointer address: " << restored << std::endl;
    std::cout << "Restored data -> id: " << restored->id
              << ", name: " << restored->name << std::endl;

    std::cout << "\n--- CHECK ---\n";

    if (restored == ptr)
        std::cout << "✅ SUCCESS: Pointers are identical!" << std::endl;
    else
        std::cout << "❌ ERROR: Pointers are different!" << std::endl;

    return 0;
}
