#!/bin/bash
##---------------SLURM Parameters - NLHPC ----------------
#SBATCH -J ejercicio4
#SBATCH -p slims
#SBATCH -n 1
#SBATCH -c 2
#SBATCH --mem-per-cpu=2400
#SBATCH --mail-user=foo@bar.com 
#SBATCH --mail-type=ALL
#SBATCH --array=1-100%10
#SBATCH -o out/ejercicio4_%A_%a.out
#SBATCH -e out/ejercicio4_%A_%a.err

ml  Python/3.8.2  

python average.py $SLURM_ARRAY_TASK_ID
