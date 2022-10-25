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
     */
    TodoEntity(std::string contenu);

    ~TodoEntity();

    /**
     * @brief Assesseur du contenu du todo
     * @return la chaine qui donne le contenu du todo
     */
    const std::string &getContenuTodo() const;

    /**
     * @brief Mutateur du contenu du todo
     * @param le nouveau contenu
     */
    void setContenuTodo(const std::string &newContenuTodo);

    /**
     * @brief Assesseur de la date d'ajout du todo
     * @return la date d'ajout du todo
     */
    const sys_days &getDateAjoutTodo() const;

private:

    /**
     * @brief Texte du todo
     */
    std::string contenuTodo;

    /**
     * @brief Date d'ajout du todo
     */
    sys_days dateAjoutTodo;

    /**
    * @brief Fonction amie qui surcharge l'operateur << pour l'affichage du todo
    */
    friend std::ostream& operator<< (ostream& os, const TodoEntity& todo);

    friend bool operator==(TodoEntity a, TodoEntity b);
};

#endif // TODOENTITY_H
