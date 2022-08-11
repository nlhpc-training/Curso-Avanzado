#!/bin/bash
##---------------SLURM Parameters - NLHPC ----------------
#SBATCH -J ejercicio3
#SBATCH -p slims
#SBATCH -n 2
#SBATCH -c 20
#SBATCH --mem-per-cpu=2400
#SBATCH --mail-user=foo@bar.com 
#SBATCH --mail-type=ALL
#SBATCH -o ejercicio3_%j.out
#SBATCH -e ejercicio3_%j.err

srun hello_hybrid
