# Flowchart: Fonction pour Imprimer des Arguments Variables

```mermaid
flowchart TD
    Start([Début: Appel de la fonction<br/>print_args args...]) --> InitCounter[Initialiser compteur i = 0]

    InitCounter --> CheckArgs{i < nombre<br/>d'arguments?}

    CheckArgs -->|Non| End1([Fin: Tous les arguments<br/>ont été imprimés])

    CheckArgs -->|Oui| GetArg[Récupérer l'argument<br/>à la position i]

    GetArg --> CheckType{Quel est le<br/>type de l'argument?}

    CheckType -->|String| PrintString[Imprimer comme chaîne]
    CheckType -->|Number| PrintNumber[Imprimer comme nombre]
    CheckType -->|Boolean| PrintBoolean[Imprimer comme booléen]
    CheckType -->|Object| PrintObject[Imprimer comme objet]
    CheckType -->|Null/Undefined| PrintNull[Imprimer null/undefined]

    PrintString --> AddSeparator{Dernier argument?}
    PrintNumber --> AddSeparator
    PrintBoolean --> AddSeparator
    PrintObject --> AddSeparator
    PrintNull --> AddSeparator

    AddSeparator -->|Non| AddSpace[Ajouter un espace/séparateur]
    AddSeparator -->|Oui| IncrementCounter

    AddSpace --> IncrementCounter[Incrémenter i = i + 1]

    IncrementCounter --> CheckArgs

    style Start fill:#90EE90
    style End1 fill:#90EE90
    style GetArg fill:#87CEEB
    style CheckType fill:#FFD700
    style PrintString fill:#FFB6C1
    style PrintNumber fill:#FFB6C1
    style PrintBoolean fill:#FFB6C1
    style PrintObject fill:#FFB6C1
    style PrintNull fill:#FFB6C1
```

## Exemples de fonctions variadiques

### JavaScript
```javascript
function printArgs(...args) {
    for (let i = 0; i < args.length; i++) {
        console.log(args[i]);
    }
}

// Utilisation
printArgs("Hello", 42, true, {name: "John"});
```

### Python
```python
def print_args(*args):
    for arg in args:
        print(arg)

# Utilisation
print_args("Hello", 42, True, {"name": "John"})
```

### C
```c
#include <stdio.h>
#include <stdarg.h>

void print_args(int count, ...) {
    va_list args;
    va_start(args, count);

    for (int i = 0; i < count; i++) {
        int value = va_arg(args, int);
        printf("%d ", value);
    }

    va_end(args);
}

// Utilisation
print_args(3, 10, 20, 30);
```

## Concepts Clés

- **Arguments Variables**: Une fonction peut accepter un nombre indéterminé d'arguments
- **Itération**: La fonction parcourt tous les arguments un par un
- **Type Checking**: Selon le langage, on peut vérifier le type de chaque argument
- **Séparateurs**: On peut ajouter des espaces ou autres séparateurs entre les arguments

## Avantages

✅ Flexibilité - Nombre d'arguments non fixé
✅ Réutilisabilité - Une seule fonction pour plusieurs cas
✅ Simplicité - Code plus propre et concis
