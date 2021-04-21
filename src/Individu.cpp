#include "Individu.h"

/**
 * @brief Constructeur de la classe Individu
 * 
 * @param name Nom de la personne
 * @param isInfected Statut d'infection de la personne
 * @param id Id de la personne
 */
Individu::Individu(std::string name, bool isInfected, int id): name_(name),isInfected_(isInfected), id_(id){
    
}