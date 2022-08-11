#!/bin/bash
##---------------SLURM Parameters - NLHPC ----------------
#SBATCH -J ejercicio1
#SBATCH -p slims
#SBATCH -n 1
#SBATCH -c 20
#SBATCH --mem-per-cpu=2400
#SBATCH --mail-user=foo@bar.com
#SBATCH --mail-type=ALL
#SBATCH -o ejercicio1_%j.out
#SBATCH -e ejercicio1_%j.err

./pi_omp
