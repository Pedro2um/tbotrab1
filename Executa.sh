make compile
clear
./prog ./exemplos/in/d18512.tsp
# Do prof
python3 ./exemplos/tsp_plot.py ./exemplos/in/d18512.tsp ./exemplos/mst/d18512.mst ./exemplos/tour/d18512.tour
# Nossa
python3 ./exemplos/tsp_plot.py ./exemplos/in/d18512.tsp ./saidas/d18512.mst ./saidas/d18512.tour