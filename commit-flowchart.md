# Flowchart: Processus de Commit Git

```mermaid
flowchart TD
    Start([Début: Vous avez fait des changements]) --> CheckStatus[Vérifier les changements<br/>git status]

    CheckStatus --> HasChanges{Des changements<br/>existent?}

    HasChanges -->|Non| End1([Fin: Rien à committer])

    HasChanges -->|Oui| AddFiles[Ajouter les fichiers<br/>git add nom_du_fichier]

    AddFiles --> WriteMessage{Écrire un bon<br/>message de commit}

    WriteMessage --> MessageType[Choisir le type:<br/>Feat / Fix / Update / Remove]

    MessageType --> CreateCommit[Créer le commit<br/>git commit -m message]

    CreateCommit --> CommitSuccess{Commit<br/>réussi?}

    CommitSuccess -->|Non| FixError[Corriger l'erreur]
    FixError --> CreateCommit

    CommitSuccess -->|Oui| ViewHistory[Optionnel: Voir l'historique<br/>git log]

    ViewHistory --> MoreChanges{Plus de changements<br/>à faire?}

    MoreChanges -->|Oui| Start
    MoreChanges -->|Non| End2([Fin: Travail sauvegardé!])

    style Start fill:#90EE90
    style End1 fill:#FFB6C1
    style End2 fill:#90EE90
    style CreateCommit fill:#87CEEB
    style MessageType fill:#FFD700
```

## Légende des types de commit

- **Feat**: Nouvelle fonctionnalité
- **Fix**: Correction de bug
- **Update**: Mise à jour d'une fonctionnalité existante
- **Remove**: Suppression de code ou fonctionnalité

## Rappel Important

> **Faites des commits souvent!** Un commit est comme un point de sauvegarde dans votre projet.
