#ifndef TODOENTITY_H
#define TODOENTITY_H
#include <iostream>
#include <date.h>
#include <list>

using namespace date;
using namespace std;
using namespace std::chrono;

/**
 * @brief Classe decrivant les todos des interactions
 */
class TodoEntity
{
public:
    /**
     * @brief Constructeur vide du todo
     */
    TodoEntity();

    /**
     * @brief Constructeur parametrique du todo
     * @param contenu le contenu sous forme d'un chaine du todo
     * @param dateAjout la date d'ajout du todo recuperer depuis la bdd
     */
    TodoEntity(int id, std::string contenu, year_month_day dateAjout);

    ~TodoEntity();

    /**
     * @brief Assesseur du contenu du todo
     * @return la chaine qui donne le contenu du todo
     */
    const std::string &getContenuTodo() const;

    /**
     * @brief Mutateur du contenu du todo
     * @param newContenuTodo le nouveau contenu
     */
    void setContenuTodo(const std::string &newContenuTodo);

    /**
     * @brief Assesseur de la date d'ajout du todo
     * @return la date d'ajout du todo
     */
    const year_month_day &getDateAjoutTodo() const;

    /**
     * @brief Assesseur du todo en base
     * @return l'id du todo
     */
    int getIdTodo() const;

    /**
     * @brief Mutateur de la date d'ajout
     * @param newDateAjoutTodo la nouvelle date
     */
    void setDateAjoutTodo(const year_month_day &newDateAjoutTodo);

private:

    /**
     * @brief Id du todo en base
     */
    int idTodo;

    /**
     * @brief Texte du todo
     */
    std::string contenuTodo;

    /**
     * @brief Date d'ajout du todo
     */
    year_month_day dateAjoutTodo;

    /**
    * @brief Fonction amie qui surcharge l'operateur << pour l'affichage du todo
    */
    friend std::ostream& operator<< (ostream& os, const TodoEntity& todo);

    /**
     * @brief Compare le contenu et la date des todos en parametres
     * @param a le premier todo a comparer
     * @param b le deuxieme todo a comparer
     * @return vrai s'ils sont identiques faux sinon
     */
    friend bool operator==(TodoEntity a, TodoEntity b);
};

#endif // TODOENTITY_H
