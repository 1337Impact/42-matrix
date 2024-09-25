import manimlib


class GraphExample(manimlib.Scene):
    def construct(self):
        axes = manimlib.Axes((-3, 10), (-1, 8))
        axes.add_coordinate_labels()

        self.play(manimlib.Write(axes, lag_ratio=0.01, run_time=1))

        # manimlib.Axes.get_graph will return the graph of a function
        sin_graph = axes.get_graph(
            lambda x: 2 * manimlib.math.sin(x),
            color=manimlib.BLUE,
        )
        # By default, it draws it so as to somewhat smoothly interpolate
        # between sampled points (x, f(x)).  If the graph is meant to have
        # a corner, though, you can set use_smoothing to False
        relu_graph = axes.get_graph(
            lambda x: max(x, 0),
            use_smoothing=False,
            color=manimlib.YELLOW,
        )
        # For discontinuous functions, you can specify the point of
        # discontinuity so that it does not try to draw over the gap.
        step_graph = axes.get_graph(
            lambda x: 2.0 if x > 3 else 1.0,
            discontinuities=[3],
            color=manimlib.GREEN,
        )

        # manimlib.Axes.get_graph_label takes in either a string or a mobject.
        # If it's a string, it treats it as a LaTeX expression.  By default
        # it places the label next to the graph near the right side, and
        # has it match the color of the graph
        sin_label = axes.get_graph_label(sin_graph, "\\sin(x)")
        relu_label = axes.get_graph_label(relu_graph, manimlib.Text("ReLU"))
        step_label = axes.get_graph_label(
            step_graph, manimlib.Text("Step"), x=4)

        self.play(
            manimlib.ShowCreation(sin_graph),
            manimlib.FadeIn(sin_label, manimlib.RIGHT),
        )
        self.wait(2)
        self.play(
            manimlib.ReplacementTransform(sin_graph, relu_graph),
            manimlib.FadeTransform(sin_label, relu_label),
        )
        self.wait()
        self.play(
            manimlib.ReplacementTransform(relu_graph, step_graph),
            manimlib.FadeTransform(relu_label, step_label),
        )
        self.wait()

        parabola = axes.get_graph(lambda x: 0.25 * x**2)
        parabola.set_stroke(manimlib.BLUE)
        self.play(
            manimlib.FadeOut(step_graph),
            manimlib.FadeOut(step_label),
            manimlib.ShowCreation(parabola)
        )
        self.wait()

        # You can use axes.input_to_graph_point, abbreviated
        # to axes.i2gp, to find a particular point on a graph
        dot = manimlib.Dot(color=manimlib.RED)
        dot.move_to(axes.i2gp(2, parabola))
        self.play(manimlib.FadeIn(dot, scale=0.5))

        # A value tracker lets us animate a parameter, usually
        # with the intent of having other mobjects update based
        # on the parameter
        x_tracker = manimlib.ValueTracker(2)
        manimlib.f_always(
            dot.move_to,
            lambda: axes.i2gp(x_tracker.get_value(), parabola)
        )

        self.play(x_tracker.animate.set_value(4), run_time=3)
        self.play(x_tracker.animate.set_value(-2), run_time=3)
        self.wait()
