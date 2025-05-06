import falcon
from jinja2 import Environment, FileSystemLoader

# Initialize Falcon API
app = falcon.App()

# Jinja2 setup
jinja2_env = Environment(loader=FileSystemLoader("templates"))

# Falcon resource to render templates
class MyResource:
    def on_get(self, req, resp):
        template = jinja2_env.get_template("index2.html")
        rendered_template = template.render(listFlag = False, items=["One", "Two", "Three"])
        resp.status = falcon.HTTP_200

        # Set the Content-Type header to indicate HTML
        resp.content_type = "text/html"

        # Use resp.body instead of resp.text to set the response body
        resp.text = rendered_template

# Add a route
app.add_route("/", MyResource())

if __name__ == "__main__":
    from wsgiref import simple_server

    # Create a simple WSGI server
    httpd = simple_server.make_server("127.0.0.1", 8000, app)

    print("Serving on http://127.0.0.1:8000")
    
    # Start serving the Falcon app
    httpd.serve_forever()
