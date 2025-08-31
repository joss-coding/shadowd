# shadowd

shadowd

Un mini servidor estilo Unix escrito en C. Su propósito es servir como backend para aplicaciones ligeras, con un enfoque en seguridad, ofuscación y control fino de memoria.

✨ Características actuales

🟦 Sistema de logs con niveles y tabulaciones jerárquicas.

🔐 Módulos de criptografía (AES, SHA-512, shadow keys).

⚙️ Pool de threads para manejar I/O concurrente.

📦 Estructura Response para transportar datos sin lidiar directamente con malloc/realloc.

🕵️ Funciones de ofuscación y desofuscación de claves.


📂 Organización del proyecto

shadowd/
├── src/        # Código fuente en C
├── include/    # Headers (.h) [pendiente separar]
├── tests/      # Casos de prueba
├── docs/       # Documentación
└── README.md   # Este archivo

🚀 Compilación

Requiere un compilador C estándar (gcc o clang) y pthreads.

# Compilar
gcc -o shadowd src/*.c -lpthread

# Ejecutar
./shadowd

📌 Ejemplo de log

===== Iniciando gen_seed =====
    [genSeed] 🟦 [ALLOC] ra (64 bytes) ... ✅ OK
        [genSeed] 🟦 [ALLOC] out (64 bytes) ... ✅ OK
        ===== Finalizando gen_seed =====

        🔮 Roadmap

        [ ] Separar headers en include/

        [ ] Agregar tests unitarios

        [ ] Implementar CLI para control del daemon

        [ ] Integrar configuración vía archivo .conf
        