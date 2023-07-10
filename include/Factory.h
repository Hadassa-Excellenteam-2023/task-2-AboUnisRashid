#pragma once

#include "macros.h"
#include <map>
#include <typeinfo>
#include <typeindex>
#include <memory>
#include <utility>

using std::unique_ptr;
using std::make_unique;

// Forward declaration of PieceEntity class
class PieceEntity;

/**
 * @brief Factory class for creating and initializing chess pieces.
 *
 * The Factory class maintains a map where the keys are the names of the pieces and the values
 * are unique pointers to the corresponding piece objects. It provides functionality to create
 * and initialize pieces on the chessboard.
 *
 * @tparam T The type of the piece to be created.
 */
template<typename T>
class Factory {
public:
    using pieceObject = std::unique_ptr<T>(*)();

    /**
     * @brief Creates a piece based on the provided piece name.
     *
     * This function looks up the piece name in the map and returns the corresponding piece object.
     * If the piece name is not found in the map, nullptr is returned.
     *
     * @param pieceName The name of the piece to create.
     * @return A unique pointer to the created piece object, or nullptr if not found.
     */
    static std::unique_ptr<T> createPiece(const char& pieceName);

    /**
     * @brief Registers a piece with the given name and object.
     *
     * This function adds the piece name and object to the map.
     *
     * @param pieceName The name of the piece to register.
     * @param piece The object representing the piece.
     * @return True if registration is successful, false otherwise.
     */
    static bool reg(const char& pieceName, pieceObject piece);

private:

    /**
     * @brief Returns a reference to the map containing the registered pieces.
     *
     * This function returns a reference to the static map that holds the registered pieces.
     * The map is lazily initialized the first time this function is called.
     *
     * @return A reference to the map of registered pieces.
     */
    static auto& getMap() {
        static std::map<char, pieceObject> m_map;
        return m_map;
    }
};


template<typename T>
std::unique_ptr<T> Factory<T>::createPiece(const char& pieceName) {
    auto piece = Factory<T>::getMap().find(pieceName);
    if (piece == Factory<T>::getMap().end())
        return nullptr;
    return piece->second();
}


template<typename T>
bool Factory<T>::reg(const char& pieceName, pieceObject piece) {
    Factory<T>::getMap().emplace(pieceName, piece);
    return true;
}
