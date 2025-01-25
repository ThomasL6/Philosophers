# Philosophers

![philosophers](https://raw.githubusercontent.com/ayogun/42-project-badges/main/badges/philosophersm.png)

## Description
Philosophers est un projet de l'École 42 qui simule le problème classique des philosophes dînant ensemble, introduisant les concepts de threading et de synchronisation.

## Objectif
Implémenter une simulation où plusieurs philosophes doivent manger, penser et dormir sans mourir de faim, en utilisant des threads et des mutex.

## Fonctionnalités

- Simulation de philosophes comme threads distincts
- Gestion des fourchettes partagées (mutex)
- États des philosophes : manger, penser, dormir
- Prévention des deadlocks et de la famine
- Affichage des actions des philosophes en temps réel

## Compilation et Exécution

make
./philo [nb_philo] [time_to_die] [time_to_eat] [time_to_sleep] [optional: nb_of_meals]

## Exemples d'utilisation

- Pour faire mourir un philosophe :
./philo 4 310 200 100

- Pour une simulation sans fin :
./philo 4 410 200 200

- Avec un nombre défini de repas :
./philo 4 410 200 200 5
