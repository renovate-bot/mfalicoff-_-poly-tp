/// Gestionnaire d'utilisateurs.
/// \author Misha Krieger-Raynauld
/// \date 2020-01-12
/// \modifié Maximiliano Falicoff: 2013658
/// \modifié Bryan junior Ngatshou : 1956611 
/// \date 2020-04-16
#include "GestionnaireUtilisateurs.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>

/// Affiche les informations des utilisateurs gérés par le gestionnaire d'utilisateurs à la sortie du stream donné.
/// \param outputStream         Le stream auquel écrire les informations des utilisateurs.
/// \param gestionnaireFilms    Le gestionnaire d'utilisateurs à afficher au stream.
/// \return                     Une référence au stream.
std::ostream& operator<<(std::ostream& outputStream, const GestionnaireUtilisateurs& gestionnaireUtilisateurs)
{
    // TODO: Uncomment une fois que la fonction getNombreUtilisateurs est écrite
    outputStream << "Le gestionnaire d'utilisateurs contient " << gestionnaireUtilisateurs.getNombreUtilisateurs()
        << " utilisateurs:\n";

    // TODO: Réécrire l'implémentation avec des range-based for et structured bindings (voir énoncé du TP)
    for (const auto& [key, value] : gestionnaireUtilisateurs.utilisateurs_)
    {
        outputStream << '\t' << value << '\n';
    }
    return outputStream;
}

/// Ajoute les utilisateurs à partir d'un fichier de données d'utilisateurs.
/// \param nomFichier   Le fichier à partir duquel lire les informations des utilisateurs.
/// \return             True si tout le chargement s'est effectué avec succès, false sinon.
bool GestionnaireUtilisateurs::chargerDepuisFichier(const std::string& nomFichier)
{
    std::ifstream fichier(nomFichier);
    if (fichier)
    {
        utilisateurs_.clear();

        bool succesParsing = true;

        std::string ligne;
        while (std::getline(fichier, ligne))
        {
            std::istringstream stream(ligne);

            std::string id;
            std::string nom;
            int age;
            int pays;

            if (stream >> id >> std::quoted(nom) >> age >> pays)
            {
                // TODO: Uncomment une fois que la fonction ajouterUtilisateur est écrite
                ajouterUtilisateur(Utilisateur{ id, nom, age, static_cast<Pays>(pays) });
            }
            else
            {
                std::cerr << "Erreur GestionnaireUtilisateurs: la ligne " << ligne
                    << " n'a pas pu être interprétée correctement\n";
                succesParsing = false;
            }
        }
        return succesParsing;
    }
    std::cerr << "Erreur GestionnaireUtilisateurs: le fichier " << nomFichier << " n'a pas pu être ouvert\n";
    return false;
}

/**
 * @brief Permet d'ajouter un utilisateur dans le gestionnaire
 *
 * @param utilisateur
 * @return true si emaplce a marche
 * @return false sinon (la cle existe deja)
 */
bool GestionnaireUtilisateurs::ajouterUtilisateur(const Utilisateur& utilisateur)
{
    return utilisateurs_.emplace(utilisateur.id, utilisateur).second;
}

/**
 * @brief Permet de supprimer un utilisateur du gestionnaire
 *
 * @param idUtilisateur
 * @return true si l'element existe et a ete efface
 * @return false sinon
 */
bool GestionnaireUtilisateurs::supprimerUtilisateur(const std::string& idUtilisateur)
{
    return utilisateurs_.erase(idUtilisateur);
}

/**
 * @brief Permet de savoir le nombre d'utilisateurs present dans le gestionnaire
 *
 * @return std::size_t
 */
std::size_t GestionnaireUtilisateurs::getNombreUtilisateurs() const
{
    return utilisateurs_.size();
}

/**
 * @brief Retourne un utilisateur dans le gestionnaire en donnatn son id
 *
 * @param id
 * @return const Utilisateur* l'utilisateur qui possede l'id
 */
const Utilisateur* GestionnaireUtilisateurs::getUtilisateurParId(const std::string& id) const
{
    auto it = utilisateurs_.find(id);
    if (it != utilisateurs_.end())
        return &(it.operator->()->second);
    return nullptr;
}

