#!/bin/bash
##---------------SLURM Parameters - NLHPC ----------------
#SBATCH -J ejercicio2
#SBATCH -p slims
#SBATCH -n 20
#SBATCH --ntasks-per-node=10
#SBATCH --mem-per-cpu=2400
#SBATCH --mail-user=foo@bar.com 
#SBATCH --mail-type=ALL
#SBATCH -o ejercicio2_%j.out
#SBATCH -e ejercicio2_%j.err

srun pi_mpi
