//
//  ContentView.swift
//  GeometryReader
//
//  Created by Achmada Fiqri A Rasyad on 01/10/20.
//

import SwiftUI

struct ContentView: View {
    var body: some View {
        GeometryReader{
            geo in
            HStack{
                Text("Hello, world!")
                    .frame(width: geo.size.width/3, height: geo.size.height/3)
                    .background(Color.blue)
                Text("Hello, world!")
                    .frame(width: geo.size.width/3, height: geo.size.height/3)
                    .background(Color.orange)
                Text("Hello, world!")
                    .frame(width: geo.size.width/3, height: geo.size.height/3)
                    .background(Color.gray)
            }
        }
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
