# Esbatussar el menjar

Clon del joc Fruit Ninja desenvolupat en Unity 6 com a projecte de curs.

## Descripció

Joc d'acció on l'objectiu és tallar tota la fruita que apareix en pantalla movent el ratolí, evitant les bombes. Inclou un sistema de rànquing local amb el top 3 de jugadors guardat en XML i integració amb Firebase.

## Característiques

- Mecànica de tall amb ratolí i traç visual (BladeTrail)
- Fruites i bombes llançades per un sistema de Spawner configurable
- Sistema de vides: perdes vida si la fruita cau sense tallar o toques una bomba
- Puntuació en temps real i rècord guardat amb PlayerPrefs
- Rànquing Top 3 persistent en fitxer XML local
- Integració amb Firebase (marcador en línia)
- Menú de pausa
- Gestió d'àudio centralitzada (AudioManager)
- Efectes de partícules en tallar la fruita
- Introduir nom de jugador per al rànquing

## Scripts principals

| Script | Funció |
|---|---|
| `GameManager.cs` | Singleton central: puntuació, rècord, inici/fi de partida |
| `Blade.cs` | Detecta el moviment del ratolí i executa els talls |
| `Spawner.cs` | Llança fruites i bombes a intervals configurables |
| `Fruit.cs` | Comportament de la fruita en ser tallada |
| `Bomb.cs` | Comportament de la bomba |
| `LivesManager.cs` | Gestió de les vides del jugador |
| `PlayerXmlScoreList.cs` | Rànquing Top 3 serialitzat en XML (bubble sort) |
| `FirebaseManager.cs` | Connexió amb Firebase per al marcador en línia |
| `AudioManager.cs` | Reproducció centralitzada de sons |
| `PauseManager.cs` | Pausa i represa de la partida |

## Tecnologies

- Unity 6
- C#
- Firebase (Realtime Database)
- XML Serialization
- PlayerPrefs

## Com executar

1. Obrir el projecte amb Unity 6
2. Obrir l'escena principal des de `Assets/Scenes/`
3. Prémer Play a l'editor o compilar per a la plataforma desitjada

## Autor

Carlos Rodriguez — La Salle Girona, DAM 2025-26
