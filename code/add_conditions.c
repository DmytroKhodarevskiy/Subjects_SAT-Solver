#include <stddef.h>
#include "cnf.h"


#include <stdio.h>
//
// LOGIN: xkhoda01
//

// Tato funkce je prikladem pouziti funkci create_new_clause, add_literal_to_clause a add_clause_to_formula
// Vysvetleni, co dela, naleznete v zadani
void example_condition(CNF *formula, unsigned num_of_subjects, unsigned num_of_semesters) {
    assert(formula != NULL);
    assert(num_of_subjects > 0);
    assert(num_of_semesters > 0);

    for (unsigned subject_i = 0; subject_i < num_of_subjects; ++subject_i) {
        for (unsigned semester_j = 0; semester_j < num_of_semesters; ++semester_j) {
            // vytvori novou klauzuli
            Clause *example_clause = create_new_clause(num_of_subjects, num_of_semesters);
            // vlozi do klauzule literal x_{i,j}
            add_literal_to_clause(example_clause, true, subject_i, semester_j);
            // vlozi do klauzule literal ~x_{i,j}
            add_literal_to_clause(example_clause, false, subject_i, semester_j);
            // prida klauzuli do formule
            add_clause_to_formula(example_clause, formula);
        }
    }
}

// Tato funkce by mela do formule pridat klauzule predstavujici podminku a)
// Predmety jsou reprezentovany cisly 0, 1, ..., num_of_subjects-1
// Semestry jsou reprezentovany cisly 0, 1, ..., num_of_semesters-1
void each_subject_enrolled_at_least_once(CNF *formula, unsigned num_of_subjects, unsigned num_of_semesters) {
    assert(formula != NULL);
    assert(num_of_subjects > 0);
    assert(num_of_semesters > 0);

    // ZDE PRIDAT KOD
    for (unsigned subject_i = 0; subject_i < num_of_subjects; ++subject_i) 
    {
        Clause *clause = create_new_clause(num_of_subjects, num_of_semesters);
        for (unsigned semester_j = 0; semester_j < num_of_semesters; ++semester_j) 
        {
            add_literal_to_clause(clause, true, subject_i, semester_j);
        }
        add_clause_to_formula(clause, formula);
    }
}

// Tato funkce by mela do formule pridat klauzule predstavujici podminku b)
// Predmety jsou reprezentovany cisly 0, 1, ..., num_of_subjects-1
// Semestry jsou reprezentovany cisly 0, 1, ..., num_of_semesters-1
void each_subject_enrolled_at_most_once(CNF *formula, unsigned num_of_subjects, unsigned num_of_semesters) {
    assert(formula != NULL);
    assert(num_of_subjects > 0);
    assert(num_of_semesters > 0);

    // ZDE PRIDAT KOD
    for (unsigned subject_i = 0; subject_i < num_of_subjects; ++subject_i)
    {
        for (unsigned semester_j = 0; semester_j < num_of_semesters; ++semester_j) 
        {
            for (unsigned semester_k = semester_j + 1; semester_k < num_of_semesters; ++semester_k) 
            {
                Clause *clause = create_new_clause(num_of_subjects, num_of_semesters);
                add_literal_to_clause(clause, false, subject_i, semester_j);
                add_literal_to_clause(clause, false, subject_i, semester_k);
                add_clause_to_formula(clause, formula);
            }
        }
    }
}


// Tato funkce by mela do formule pridat klauzule predstavujici podminku c)
// Promenna prerequisities obsahuje pole s poctem prvku rovnym num_of_prerequisities
// Predmety jsou reprezentovany cisly 0, 1, ..., num_of_subjects-1
// Semestry jsou reprezentovany cisly 0, 1, ..., num_of_semesters-1
void add_prerequisities_to_formula(CNF *formula, Prerequisity* prerequisities, unsigned num_of_prerequisities, unsigned num_of_subjects, unsigned num_of_semesters) {
    assert(formula != NULL);
    assert(prerequisities != NULL);
    assert(num_of_subjects > 0);
    assert(num_of_semesters > 0);

    // printf("%d, %d\n", prerequisities[0].earlier_subject, prerequisities[num_of_prerequisities-1].later_subject);
    // int chain_counter = 1;

    for (unsigned i = 0; i < num_of_prerequisities; ++i) {
        // prerequisities[i].earlier_subject je predmet, ktery by si mel student zapsat v nekterem semestru pred predmetem prerequisities[i].later_subject

        // ZDE PRIDAT KOD
        // printf("chain_counter: %d\n", chain_counter);
        // if ((prerequisities[0].earlier_subject == prerequisities[num_of_prerequisities-1].later_subject) ||
        //    (chain_counter == num_of_semesters && i == num_of_prerequisities-1)) {
        //     // The prerequisite is not satisfied for this pair of subjects
        //     for (unsigned subject = 0; subject < num_of_subjects; subject++) 
        //     {
        //         for (unsigned semester = 0; semester < num_of_semesters; semester++) 
        //         {
        //             Clause *clause = create_new_clause(num_of_subjects, num_of_semesters);
        //             //i need to make it UNSATISFIABLE
        //             add_literal_to_clause(clause, false, subject, semester);
        //             // add_literal_to_clause(clause, true, subject, semester);
        //             add_clause_to_formula(clause, formula);

        //         }   
        //     }
        //     break;
        // }
        
        // if (prerequisities[i].later_subject == prerequisities[i+1].earlier_subject) 
        // {
        //     chain_counter++;
        // }

        for (unsigned semester_j = 0; semester_j < num_of_semesters; ++semester_j) {
        
            Clause *clause = create_new_clause(num_of_subjects, num_of_semesters);
            if (semester_j + 1 == num_of_semesters)
            {
                add_literal_to_clause(clause, false, prerequisities[i].earlier_subject, semester_j);
                add_clause_to_formula(clause, formula);
                break;
            }
            // for (unsigned semester_i = semester_j; semester_i > 0; semester_i--)
            // {
            //     add_literal_to_clause(clause, true, prerequisities[i].earlier_subject, semester_i);
            // }
            // add_literal_to_clause(clause, true, prerequisities[i].earlier_subject, semester_j);

            // add_literal_to_clause(clause, true, prerequisities[i].earlier_subject, semester_j);
            // for (unsigned semester_k = semester_j + 1; semester_k < num_of_semesters; semester_k++) 
            // {
            //     add_literal_to_clause(clause, false, prerequisities[i].earlier_subject, semester_k);
            // }
            // add_clause_to_formula(clause, formula);

            add_literal_to_clause(clause, false, prerequisities[i].earlier_subject, semester_j);
            for (unsigned semester_k = semester_j + 1; semester_k < num_of_semesters; ++semester_k) 
            {
                add_literal_to_clause(clause, true, prerequisities[i].later_subject, semester_k);
            }

            add_clause_to_formula(clause, formula);

        }    

        // for (unsigned semester_j = 0; semester_j < num_of_semesters; semester_j++) {
            
        //     Clause *clause2 = create_new_clause(num_of_subjects, num_of_semesters);
        //     if (semester_j + 1 == num_of_semesters)
        //     {
        //         // add_literal_to_clause(clause2, true, prerequisities[i].later_subject, semester_j);
        //         // add_clause_to_formula(clause2, formula);
        //         break;
        //     }
        //     // for (unsigned semester_i = semester_j; semester_i > 0; semester_i--)
        //     // {
        //     //     add_literal_to_clause(clause2, false, prerequisities[i].later_subject, semester_i);
        //     // }
        //     // add_literal_to_clause(clause2, false, prerequisities[i].later_subject, semester_j);

        //     add_literal_to_clause(clause2, false, prerequisities[i].later_subject, semester_j);
        //     for (unsigned semester_k = semester_j + 1; semester_k < num_of_semesters; semester_k++) 
        //     {
        //         add_literal_to_clause(clause2, true, prerequisities[i].later_subject, semester_k);
        //     }
        //     add_clause_to_formula(clause2, formula);
        // }        
    }
    
}
