make compile
clear
# Do prof
python3 ./exemplos/tsp_plot.py ./exemplos/in/a280.tsp ./exemplos/mst/a280.mst ./exemplos/tour/a280.tour
# Nossa
python3 ./exemplos/tsp_plot.py ./exemplos/in/a280.tsp ./saidas/a280.mst ./saidas/a280.tour